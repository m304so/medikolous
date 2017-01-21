<?php
require_once 'doctor.model.inc';

class DoctorController extends mainController {
	
	private $_model;
	
	public function __construct() {
		parent::__construct();
		$this->_model = new Doctor();
	}
	
	public function index() {
		$this->Smarty->assign('title', 'Medical reception system');
		$this->Smarty->assign('description', 'Доступные специальности');
		$this->Smarty->assign('tpl', 'p-doctor-index.tpl');
		$this->Smarty->display('main.tpl');	
	}
}