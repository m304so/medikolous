<?php

require_once 'model.class.inc';

class User extends Model {

	public function __construct() {
		parent::__construct();
	}

	/**
	 * Обновить пользователя
	 *  
	 * @param type $id
	 * @param type $data
	 * @param type $specialties
	 * @param type $clinicName
	 * @return bollean
	 */
	public function update($id, $data, $specialties, $clinicName) {
		return true;
	}

	/**
	 * Добавить пользователя
	 *  
	 * @param type $data
	 * @param type $specialties
	 * @param type $clinicName
	 * @return bollean
	 */
	public function insert($data, $specialties, $clinicName) {
		return true;
	}
	
	public function getUserByFIO($surname, $name, $patronymic) {
		return false;
	}
	
	public function getCategoryIds($specialties) {
		return false;
	}

	public function getClinicByName($name) {
		return false;
	}
}
