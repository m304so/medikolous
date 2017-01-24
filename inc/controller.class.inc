<?php

require_once './lib/smarty/Smarty.class.php';

class mainController {

	private $_Smarty;
	private $_templateDir = 'templates';
	private $_compileDir = 'templates_c';

	/** @var string Базовый конструктор шаблонов */
	private $_baseTemplate = 'main.tpl';

	/** @var array Массив базовых параметров, передаваемых в шаблон */
	private $_baseAssign = [
		'title' => 'Регистратура',
		'logo' => 'Регистратура',
		'tpl' => 'p-index.tpl'
	];

	public function __construct() {
		if (!isset($this->_baseAssign['login']) && isset($_SESSION['login'])) {
			$this->_baseAssign['login'] = true;
		}
		if (!isset($this->_baseAssign['access_level']) && isset($_SESSION['access_level'])) {
			$this->_baseAssign['moderator'] = ($this->access('moderate')) ? true : false;
		}
		$this->_getSmartyInstance();
	}

	/** @var array Массив параметров, передаваемых в шаблон */
	private $_assign = [];

	/**
	 * Установить передаваемые в шаблон параметры
	 * 
	 * @param array $assigns Массив параметров, передаваемых в шаблон
	 */
	public function setAssigns($assigns) {
		if (is_array($assigns) && !empty($assigns)) {
			foreach ($assigns as $key => $value) {
				if (is_int($key)) {
					unset($assigns[$key]);
				}
			}
			if (sizeof($assigns) > 0) {
				$this->_assign = $assigns;
			}
		}
	}

	/**
	 * Проверка на наличие прав
	 * 
	 * @param type $param
	 * @return boolean
	 */
	public function access($param) {
		$accessLevel = $_SESSION['access_level'];
		switch($param) {
			case 'moderate':
				$result = ($accessLevel >= 3) ? true : false;
				break;
			case 'administrate':
				$result = ($accessLevel == 7) ? true : false;
				break;
			default :
				$result = false;
				break;
			
		}
		return $result;
	}
	
	/**
	 * Получить экземпляр объекта Smarty
	 */
	private function _getSmartyInstance() {
		if (!$this->_Smarty) {
			$this->_Smarty = new Smarty();
			$this->_Smarty->template_dir = $this->_templateDir;
			$this->_Smarty->compile_dir = $this->_compileDir;
		}
	}

	/**
	 * Вывод шаблона главной страницы
	 * 
	 * @return void
	 */
	public function index() {
		$this->showView();
	}

	/**
	 * Вывод шаблона страницы
	 * 
	 * @param string $base Ссылка на базовый шаблон-конструктор
	 * @return void
	 */
	public function showView($base = false) {
		$tpl = ($base) ? $base : $this->_baseTemplate;
		$assigns = array_merge($this->_baseAssign, $this->_assign);
		foreach ($assigns as $key => $value) {
			$this->_Smarty->assign($key, $value);
		}
		$this->_Smarty->display($tpl);
	}

	/**
	 * Проверка на Ajax
	 * 
	 * @return boolean
	 */
	public function isAjax() {
		return isset($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest';
	}

	/**
	 * Редирект
	 * 
	 * @param string $path Путь для перенаправления
	 * @param boolean $condition Условие, если true, то перенаправлять
	 * @return void
	 */
	public function redirect($condition = true, $path = '../') {
		if ($condition) {
			header('Location: ' . $path);
		}
	}

	/**
	 * Возврат массива с конвертацие в json
	 * 
	 * @param array $data Массив данных
	 */
	public function jsonReturn($data) {
		echo json_encode($data);
		exit();
	}

}
