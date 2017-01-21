<?php
require_once 'visitor.model.inc';

class VisitorController extends mainController {
	
	private $_model;
	
	public function __construct() {
		parent::__construct();
		$this->_model = new Visitor();
	}
}