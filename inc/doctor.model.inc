<?php

require_once 'model.class.inc';

class Doctor extends Model {

	public function __construct() {
		parent::__construct();
	}

	public function getDoctorsPage($from = 1, $perPage = 10) {
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
		return $this->db->getArray($query, $params);
	}
	
	public function getDoctorsCount() {
		return $this->db->getArray('SELECT count(*) FROM users');
	}
}
