<?php

require_once './lib/smarty/Smarty.class.php';

class mainController {

	public $Smarty;

	public function __construct() {
		$this->_smartyInstance();
	}

	private function _smartyInstance() {
		if (!$this->Smarty) {
			$this->Smarty = new Smarty();
			$this->Smarty->template_dir = 'templates';
			$this->Smarty->compile_dir = 'templates_c';
		}
	}

	public function index() {
		$this->Smarty->assign('title', 'Medical reception system');
		$this->Smarty->assign('description', 'Система записи на прием к врачу');
		$this->Smarty->assign('tpl', 'p-index.tpl');
		$this->Smarty->display('main.tpl');
	}

}
