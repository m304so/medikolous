<?php

require_once 'doctor.model.inc';

class DoctorController extends mainController {

	private $_model;

	public function __construct() {
		parent::__construct();
		$this->_model = new Doctor();
		$assigns = [
			'menu' => 'doctors'
		];
		$this->setAssigns($assigns);
	}

	public function index() {
		$dCount = $this->_model->getDoctorsCount();
		$doctors = $this->_model->getDoctorsPage(0, 50);
		$assigns = [
			'doctors' => $doctors,
			'tpl' => 'p-doctor-index.tpl'
		];
		$this->setAssigns($assigns);
		$this->showView();
	}

	public function editor($param) {
		$doctor = $this->_model->getDoctorById((int) $param);
		$assigns = [
			'doctor' => $doctor[0],
			'tpl' => 'p-doctor-editor.tpl'
		];
		$this->setAssigns($assigns);
		$this->showView();
	}
	
	public function visit($param) {
		$doctor = $this->_model->getDoctorById((int) $param);
		$assigns = [
			'doctor' => $doctor[0],
			'tpl' => 'p-doctor-visit.tpl'
		];
		$this->setAssigns($assigns);
		$this->showView();
	}

	public function addVisitor() {
		$this->redirect(!$this->isAjax());
		$doctorId = (int) $_POST['doctorId'];
		$visitdate = $_POST['visitdate'] . ':00';
		$name = htmlentities($_POST['name'], ENT_QUOTES);
		$surname = htmlentities($_POST['surname'], ENT_QUOTES);
		$patronymic = htmlentities($_POST['patronymic'], ENT_QUOTES);
		$data = $this->_model->addVisitor($doctorId, $visitdate, $name, $surname, $patronymic);
		$this->jsonReturn($data);
	}

	public function addNew() {
		$this->redirect(!$this->isAjax());
		$assigns = [
			'tpl' => 'p-doctor-editor.tpl',
			'isNew' => true
		];
		$this->setAssigns($assigns);
		$this->showView();
	}

}
