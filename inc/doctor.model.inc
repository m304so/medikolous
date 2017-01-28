<?php

require_once 'model.class.inc';

class Doctor extends Model {

	public function __construct() {
		parent::__construct();
	}

	public function getDoctorsPage($from = 0, $perPage = 10) {
		$query = '
		SELECT
			u.id,
			u.name,
			u.surname,
			u.patronymic,
			u.link,
			u.avatar,
			u.adult_group as adultGroup,
			c.name as clinicName,
			c.link as clinicLink
		FROM users u
		LEFT JOIN clinics c
			   ON c.id = u.clinic_id
		LIMIT ' . (int) $from . ',' . (int) $perPage;
		return $this->db->getArray($query);
	}

	public function getDoctorById($userId) {
		$params = [
			':id' => $userId
		];
		$query = '
		SELECT
			u.id,
			u.name,
			u.surname,
			u.patronymic,
			u.link,
			u.avatar,
			u.adult_group as adultGroup,
			c.name as clinicName,
			c.link as clinicLink
		FROM users u
		LEFT JOIN clinics c
			   ON c.id = u.clinic_id
		WHERE u.id = :id';
		return $this->db->getArray($query, $params);
	}

	public function getDoctorsCount() {
		return $this->db->getArray('SELECT count(*) FROM users');
	}

	public function addVisitor($doctorId, $visitdate, $name, $surname, $patronymic) {
		$params = [
			':id' => $doctorId,
			':dt' => $visitdate
		];
		$check = $this->db->getArray('SELECT 1 FROM log WHERE doctor_id = :id AND dt_visit = :dt', $params);
		if (!$check) {
			$params = [
				':id' => $doctorId,
				':dt' => $visitdate,
				':name' => $name,
				':surname' => $surname,
				':patronymic' => $patronymic,
			];
			$this->db->execute('INSERT INTO log (name, surname, patronymic, doctor_id, dt_visit) VALUES (:name, :surname, :patronymic, :id, :dt)', $params);
			$answer = ['result' => true];
		} else {
			$answer = ['result' => false];
		}
		return $answer;
	}

}
