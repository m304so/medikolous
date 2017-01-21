<?php

require_once 'db.class.inc';

class Model {

	public $db;

	public function __construct() {
		$this->_dbInstanse();
	}

	private function _dbInstanse() {
		if (!$this->db) {
			$this->db = new DB();
		}
	}

}
