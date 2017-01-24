<?php

require_once 'parser.model.inc';

class ParserController extends mainController {

	private $_model;
	private $_citeUrl = 'http://napopravku.ru/';

	public function __construct() {
		$this->redirect(!$this->access('moderate'));
		parent::__construct();
		$this->_model = new Parser();
	}

	/**
	 * Главная страница парсера
	 * @return void
	 */
	public function index() {
		set_time_limit(0);
		$result = $this->_startParsing(1, 1);
		log::dump($result);
		die();
		$assigns = [
			'tpl' => 'p-parser-index.tpl',
			'logo' => 'Парсер'
		];
		$this->setAssigns($assigns);
		$this->showView();
	}

	/**
	 * Начать парсинг
	 * 
	 * @param integer $startPage Страница с которой начать работу парсера
	 * @param integer $count Количество сканируемых страниц
	 * @return array
	 */
	private function _startParsing($startPage = 0, $count = 1) {
		$personalData = [];
		for ($i = 0; $i < $count; $i++) {
			$url = 'http://napopravku.ru/doctors/?type=doctors&speciality=&category=&name=&doctor=&sex=&sortingField=rating&sortingDir=desc&pageSize=10&filter=Y&PAGEN_1=' . (string) ($startPage + $i);
			$tmpPath = './tmp/PAGEN_1=' . (string) ($startPage + $i) . '.txt';
			if (!file_exists($tmpPath)) {
				$tmpFile = fopen($tmpPath, 'w');
				$content = file_get_contents($url);
				fwrite($tmpFile, $content);
				fclose($tmpFile);
			} else {
				$content = file_get_contents($tmpPath);
			}
			$info = $this->_getLinksAndFIO($content);
			$avatars = $this->_getAvatarLinks($content);
			$clinicLinks = $this->_getClinicLinks($content);
			$clinicNames = $this->_getClinicNames($content);
			$adultGroup = $this->_getAdultGroup($content);
			$specialties = $this->_getSpecialties($content);
			$personalData = $this->_prepareResultArray($info, $avatars, $adultGroup, $clinicNames, $clinicLinks, $specialties, $specialties);
		}
		return $personalData;
	}

	/**
	 * Возвращает сгруппированные массивы ФИО
	 * 
	 * @param string $html Содержимое HTML-страницы
	 * @return array 0 - name, 1 - surname, 2 - patronymic
	 */
	private function _getLinksAndFIO($html) {
		$result = [];
		$matches = [];
		$pattern = '/data-event="clickdoctor" href="\/([^"]*)"[^>]*>([^<]*)/';
		preg_match_all($pattern, $html, $matches);
		$fioArray = $matches[2];
		$linkArray = $matches[1];
		$cnt = sizeof($fioArray);
		for ($i = 0; $i < $cnt; $i++) {
			$string = trim($fioArray[$i]);
			if ($string !== '') {
				$fio = explode(' ', $string);
				$result[] = [
					'name' => $fio[0],
					'surname' => $fio[1],
					'patronymic' => $fio[2]
				];
			}
		}
		$count = sizeof($result);
		for ($i = 0; $i < $count; $i++) {
			$result[$i]['link'] = $this->_citeUrl . $linkArray[$i];
		}
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
		return $this->_model->simpleParse($html, $pattern, [2,4,6,8], 'specialties');
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
		return ['adultGroup' => $result];
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

	public function saveNewDoctor() {

		fwrite($file, trim($_POST['name']) . ' ' . trim($_POST['surname']) . ' ' . trim($_POST['patronymic']) . "\n" . trim($_POST['speciality']) . "\n\n");
		fclose($file);
	}

}
