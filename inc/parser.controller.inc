<?php

require_once 'parser.model.inc';
require_once 'user.model.inc';

class ParserController extends mainController {

	private $_model;
	private $_citeUrl = 'http://napopravku.ru/';
	private $_User;

	public function __construct() {
		$this->redirect(!$this->access('moderate'));
		parent::__construct();
		$this->_model = new Parser();
		$this->_User = new User();
	}

	/**
	 * Главная страница парсера
	 * @return void
	 */
	public function index() {
		$assigns = [
			'menu' => 'parser',
			'tpl' => 'p-parser-index.tpl'
		];
		$this->setAssigns($assigns);
		$this->showView();
	}

	/**
	 * Начать разбор страниц
	 * 
	 * @return json array
	 */
	public function parse() {
		$this->redirect(!$this->isAjax());
		$pageNumber = (int) $_POST['pageNumber'];
		$data = $this->_getDataFromPage($pageNumber);
		if (!$result = $this->_saveUsers($data)) {
			$answer = [
				'result' => false,
				'error' => 'Не удалось сохранить данные',
				'data' => $data
			];
		} else {
			$answer = [
				'result' => true,
				'amountInsert' => $result['amountInsert'],
				'amountUpdate' => $result['amountUpdate'],
				'data' => $data
			];
		}
		$this->jsonReturn($answer);
	}

	/**
	 * Получить данные со страницы
	 * 
	 * @param integer $pageNum Номер страницы для сканирования
	 * @return array
	 */
	private function _getDataFromPage($pageNum) {
		$personalData = [];
		$url = 'http://napopravku.ru/doctors/?type=doctors&speciality=&category=&name=&doctor=&sex=&sortingField=rating&sortingDir=desc&pageSize=10&filter=Y&PAGEN_1=' . $pageNum;
		$tmpPath = './tmp/PAGEN_1=' . $pageNum . '.txt';
		if (!file_exists($tmpPath)) {
			$tmpFile = fopen($tmpPath, 'w');
			$content = file_get_contents($url);
			fwrite($tmpFile, $content);
			fclose($tmpFile);
		} else {
			$content = file_get_contents($tmpPath);
		}
		$info = $this->_getLinkAndFIO($content);
		$avatars = $this->_getAvatarLinks($content);
		$clinicLinks = $this->_getClinicLinks($content);
		$clinicNames = $this->_getClinicNames($content);
		$adultGroup = $this->_getAdultGroup($content);
		$specialties = $this->_getSpecialties($content);
		$personalData = $this->_prepareResultArray($info, $avatars, $adultGroup, $clinicNames, $clinicLinks, $specialties, $specialties);
		return $personalData;
	}

	/**
	 * Возвращает ссылки на изображения
	 * 
	 * @param string $html Содержимое HTML-страницы
	 * @return array
	 */
	private function _getLinkAndFIO($html) {
		$pattern = '/class="uline js-analytics split-none" data-goal="up-doctors" target="_blank" data-event="click" data-split-action="clickdoctor" data-event="clickdoctor" href="\/([^"]*)">([^<]*)/';
		$info = $this->_model->simpleParse($html, $pattern, [1,2], 'string');
		$count = sizeof($info['string']);
		for ($i = 0; $i < $count; $i++) {
			$tmp = explode(' ', $info['string'][$i][1]);
			$result[] = [
				'name' => $tmp[0],
				'surname' => $tmp[1],
				'patronymic' => $tmp[2],
				'link' => $this->_citeUrl . $info['string'][$i][0]
			];
		}
		return $result;
	}

	/**
	 * Возвращает ссылки на изображения
	 * 
	 * @param string $html Содержимое HTML-страницы
	 * @return array
	 */
	private function _getLink($html) {
		$pattern = '/a class="pic js-analytics split-none" data-goal="up-doctors" target="_blank" data-event="click" data-split-action="clickdoctor" data-event="clickdoctor"[^>]*>([^<]*)/';
		$result = $this->_model->simpleParse($html, $pattern, 1, 'link');
		return $result;
	}

	/**
	 * Возвращает ссылки на изображения
	 * 
	 * @param string $html Содержимое HTML-страницы
	 * @return array
	 */
	private function _getAvatarLinks($html) {
		$pattern = '/upload\/resize_cache\/iblock\/([^"]*)/';
		return $this->_model->simpleParse($html, $pattern, 0, 'avatar', $this->_citeUrl, true);
	}

	/**
	 * Возвращает ссылку на адрес клиники
	 * 
	 * @param string $html Содержимое HTML-страницы
	 * @return array
	 */
	private function _getClinicLinks($html) {
		$pattern = '/color-blue" href="\/(clinics\/([^"]*))/';
		return $this->_model->simpleParse($html, $pattern, 1, 'clinicLink', $this->_citeUrl, true);
	}

	/**
	 * Возвращает ссылку на адрес клиники
	 * 
	 * @param string $html Содержимое HTML-страницы
	 * @return array
	 */
	private function _getClinicNames($html) {
		$pattern = '/place"[^\_]*_blank"\s?>([^<]*)/';
		return $this->_model->simpleParse($html, $pattern, 1, 'clinicName');
	}

	/**
	 * Возвращает ссылку на адрес клиники
	 * 
	 * @param string $html Содержимое HTML-страницы
	 * @return array
	 */
	private function _getSpecialties($html) {
		$pattern = '/specialization">([^_]*_blank"><span>([^<]*))?([^_]*_blank"><span>([^<]*))?([^_]*_blank"><span>([^<]*))?([^_]*_blank"><span>([^<]*))?([^_]*_blank"><span>([^<]*))?([^_]*_blank"><span>([^<]*))?/';
		return $this->_model->simpleParse($html, $pattern, [2, 4, 6, 8], 'specialties');
	}

	/**
	 * Возвращаяет массив возрастных групп
	 * 
	 * @param string $html Содержимое HTML-страницы
	 * @return array
	 */
	private function _getAdultGroup($html) {
		$matches = [];
		$result = [];
		$pattern = '/(adult-list)(.*[^m]*mma">([^<]*))?(.*[^m]*mma">([^<]*))?/';
		preg_match_all($pattern, $html, $matches);
		$count = sizeof($matches[3]);
		for ($i = 0; $i < $count; $i++) {
			$first = $this->_getAdultId($matches[3][$i]);
			$second = $this->_getAdultId($matches[5][$i]);
			$result[] = $first + $second;
		}
		return ['adult_group' => $result];
	}

	/**
	 * Определение возрастной категории
	 * 0 - без категории (по умолчанию)
	 * 1 - взрослый
	 * 2 - детский
	 * 3 - взрослый и детский
	 * @param string $match Строка для сравнения
	 * @return integer
	 */
	private function _getAdultId($match) {
		switch ($match) {
			case 'взрослый':
				$result = 1;
				break;
			case 'детский':
				$result = 2;
				break;
			default:
				$result = 0;
				break;
		}
		return $result;
	}

	/**
	 * Сгруппировать результаты парсеров в единый массив
	 * _prepareResultArray(array1, ... , arrayN)
	 * 
	 * @param array1 - результирующий массив
	 * @param arrayN - массив для слияния 
	 * @return array
	 */
	private function _prepareResultArray() {
		$numargs = func_num_args();
		$result = func_get_arg(0);
		$count = sizeof($result);
		for ($i = 1; $i < $numargs; $i++) {
			$array = func_get_arg($i);
			$key = key($array);
			for ($j = 0; $j < $count; $j++) {
				$result[$j][$key] = $array[$key][$j];
			}
		}
		return $result;
	}

	/**
	 * Сохранить пользователей, стянутых парсером
	 * 
	 * 1) Проверить наличие пользователя в базе
	 * 		* если есть, сравнить данные
	 * 			* если разные обновить, увеличит счетчик
	 * 		* если нет сохранить
	 * 2) Проверить наличие специальности в БД
	 * 		* если нет, сохранить, если есть, получить ID
	 * 4) Провырить наличие поликлиники в БД
	 * 		* если нет, обновить, если есть, выдать ID
	 * 
	 * @param type $data
	 */
	private function _saveUsers($data) {
		$count = count($data);
		$answer = [
			'amountInsert' => 0,
			'amountUpdate' => 0
		];

// Проверить специальности пользователя
//		foreach ($us as $spec) {
//			if ($key = array_search('red', $array)) {
//				unset($spec);
//				unset($array[$key]);
//			}
//		}
// Если после этой операции остались записи то обновить инфу (удалить лишние из базы, добавить новые)
		for ($i = 0; $i < $count; $i++) {
			$user = $this->_User->getUserByFIO($data[$i]['name'], $data[$i]['surname'], $data[$i]['patronymic']);
			$clinic = $this->_User->getClinicIdByName($data[$i]['clinicName'], $data[$i]['clinicLink']);
			$params = [
				'name' => $data[$i]['name'],
				'surname' => $data[$i]['surname'],
				'patronymic' => $data[$i]['patronymic'],
				'avatar' => $data[$i]['avatar'],
				'link' => $data[$i]['link'],
				'adult_group' => $data[$i]['adult_group'],
				'clinic_id' => $clinic
			];
			if (!$user || empty($user)) {
				if ($this->_User->insert($params)) {
					++$answer['amountInsert'];
				}
			} else {
				if ($this->_User->update((int) $user[0]['id'], $params)) {
					++$answer['amountUpdate'];
				}
			}
		}
		return $answer;
	}

}
