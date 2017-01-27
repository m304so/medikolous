<?php

require_once 'model.class.inc';

class User extends Model {
	
	public function __construct() {
		parent::__construct();
	}

	/**
	 * Обновить пользователя
	 *  
	 * @param type $userId
	 * @param type $data
	 * @param type $specialties
	 * @param type $clinicName
	 * @return bollean
	 */
	public function update($userId, $data, $specialties = false) {
		$query = 'UPDATE users SET name = :name, surname = :surname, patronymic = :patronymic, avatar = :avatar, link = :link, adult_group = :adult_group, clinic_id = :clinic_id WHERE id = :id';
		$params = [
			':id' => $userId,
			':name' => $data['name'],
			':surname' => $data['surname'],
			':patronymic' => $data['patronymic'],
			':avatar' => $data['avatar'],
			':link' => $data['link'],
			':adult_group' => $data['adult_group'],
			':clinic_id' => $data['clinic_id']
		];
		return $this->db->execute($query, $params);
	}

	/**
	 * Добавить пользователя
	 *  
	 * @param type $data
	 * @param type $specialties
	 * @param type $clinicName
	 * @return bollean
	 */
	public function insert($data, $specialties = false) {
		$query = 'INSERT INTO users (name, surname, patronymic, avatar, link, adult_group, clinic_id) VALUES (:name, :surname, :patronymic, :avatar, :link, :adult_group, :clinic_id)';
		$params = [
			':name' => $data['name'],
			':surname' => $data['surname'],
			':patronymic' => $data['patronymic'],
			':avatar' => $data['avatar'],
			':link' => $data['link'],
			':adult_group' => $data['adult_group'],
			':clinic_id' => $data['clinic_id']
		];
		return $this->db->execute($query, $params);
	}

	public function getUserByFIO($name, $surname, $patronymic) {
		$query = 'SELECT * FROM users WHERE name = :name AND surname = :surname AND patronymic = :patronymic';
		$params = [
			':name' => $name,
			':surname' => $surname,
			':patronymic' => $patronymic
		];
		return $this->db->getArray($query, $params);
	}

	public function getSpecialtiesIds($specialties) {
		$query = 'SELECT * FROM specialties WHERE name = :name';
		$params = [
			':name' => $name
		];
		return $this->db->getArray($query, $params);
	}

	public function getClinicIdByName($name, $link) {
		$query = 'SELECT id FROM clinics WHERE name = :name';
		$params = [
			':name' => $name
		];
		$result = $this->db->getArray($query, $params);
		if (empty($result)) {
			$query = 'INSERT INTO clinics (name, link) VALUES (:name, :link)';
			$params = [
				':name' => $name,
				':link' => $link
			];
			$this->db->execute($query, $params);
			return $this->db->lastID();
		} else {
			return $result[0]['id'];
		}
	}

}
