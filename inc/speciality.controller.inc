<?php
require_once 'speciality.model.inc';

class SpecialityController extends mainController {
	
	private $_model;
	
	public function __construct() {
		parent::__construct();
		$this->_model = new Speciality();
	}
	
	public function index() {
		$specialties = $this->_model->getAll();
		$count = sizeof($specialties);
		$result = [];
		$categoryCount = 0;
		for ($i = 0; $i < $count; $i++) {
			if ($currentCategory != $specialties[$i]['category']) {
				$currentCategory = $specialties[$i]['category'];
				++$categoryCount;
			}
			unset ($specialties[$i]['category']);
			$rowNum = intval($categoryCount/4);
			$result[$currentCategory][] = $specialties[$i];
		}

		$this->Smarty->assign('title', 'Medical reception system');
		$this->Smarty->assign('description', 'Доступные специальности');
		$this->Smarty->assign('specialties', $result);
		$this->Smarty->assign('tpl', 'p-speciality-index.tpl');
		$this->Smarty->display('main.tpl');	
	}
	
	public function showAll() {
		
	}
}