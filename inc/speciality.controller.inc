<?php

require_once 'speciality.model.inc';

class SpecialityController extends mainController {

	private $_model;

	public function __construct() {
		parent::__construct();
		$this->_model = new Speciality();
	}

	public function index() {
		$assigns = [
			'menu' => 'speciality',
			'tpl' => 'p-speciality-index.tpl',
			'title' => 'Специальности',
			'description' => 'Доступные специальности',
			'specialties' => $this->getCategoriesList()
		];
		$this->setAssigns($assigns);
		$this->showView();
	}

	public function edit() {
		$this->showView();
	}

	private function getCategoriesList() {
		return false;
		$result = [];
		$categoryCount = 0;
		$specialties = $this->_model->getAll();
		$count = sizeof($specialties);
		for ($i = 0; $i < $count; $i++) {
			if ($currentCategory != $specialties[$i]['category']) {
				$currentCategory = $specialties[$i]['category'];
				++$categoryCount;
			}
			unset($specialties[$i]['category']);
			$rowNum = intval($categoryCount / 4);
			$result[$currentCategory][] = $specialties[$i];
		}
		return $result;
	}

}
