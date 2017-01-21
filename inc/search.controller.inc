<?php
require_once 'search.model.inc';

class SearchController extends mainController {
	
	private $_model;
	
	public function __construct() {
		parent::__construct();
		$this->_model = new Search();
	}
	
	public function index() {
		$this->Smarty->assign('title', 'Medical reception system');
		$this->Smarty->assign('description', 'Доступные специальности');
		$this->Smarty->assign('tpl', 'p-search-index.tpl');
		$this->Smarty->display('main.tpl');	
	}
}