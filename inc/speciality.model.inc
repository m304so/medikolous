<?php

require_once 'model.class.inc';

class Speciality extends Model {

	public function __construct() {
		parent::__construct();
	}

	public function getAll() {
		return $this->db->getArray('SELECT * FROM specialties');
	}

}
