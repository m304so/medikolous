<?php
require_once 'visitor.model.inc';

class VisitorController extends mainController {
	
	private $_model;
	
	public function __construct() {
		parent::__construct();
		$this->_model = new Visitor();
	}
	
	public function index() {
		$this->Smarty->assign('title', 'Medical reception system');
		$this->Smarty->assign('description', 'Доступные специальности');
		$this->Smarty->assign('tpl', 'p-visitor-index.tpl');
		$this->Smarty->display('main.tpl');	
	}
}