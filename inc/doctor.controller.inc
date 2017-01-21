<?php
require_once 'doctor.model.inc';

class DoctorController extends mainController {
	
	private $_model;
	
	public function __construct() {
		parent::__construct();
		$this->_model = new Doctor();
	}
}