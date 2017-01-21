<?php
require_once 'auth.model.inc';

class AuthController extends mainController {
	
	private $_model;
	
	public function __construct() {
		parent::__construct();
		$this->_model = new Auth();
	}
}