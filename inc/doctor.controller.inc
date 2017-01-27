<?php

require_once 'doctor.model.inc';

class DoctorController extends mainController {

	private $_model;

	public function __construct() {
		parent::__construct();
		$this->_model = new Doctor();
	}

	public function index() {
		$dCount = $this->_model->getDoctorsCount();
		$doctors = $this->_model->getDoctorsPage(1);
		$assigns = [
			'doctors' => $doctors,
			'tpl' => 'p-doctor-index.tpl'
		];
		$this->setAssigns($assigns);
		$this->showView();
	}

	public function editor() {
		$assigns = [
			'tpl' => 'p-doctor-editor.tpl'
		];
		$this->setAssigns($assigns);
		$this->showView();
	}

	public function addNew() {
		$assigns = [
			'tpl' => 'p-doctor-editor.tpl',
			'isNew' => true
		];
		$this->setAssigns($assigns);
		$this->showView();
	}

}
