<?php

require_once 'model.class.inc';

class Journal extends Model {

	public function __construct() {
		parent::__construct();
	}

	public function getVisitorsAll() {
		$query = '
		SELECT
			u.id,
			u.name as doctorName,
			u.surname as doctorSurname,
			u.patronymic as doctorPatronymic,
			u.link,
			u.avatar,
			u.adult_group as adultGroup,
			l.*,
			c.name as clinicName,
			c.link as clinicLink
		FROM log l
		LEFT JOIN users u
			   ON l.doctor_id = u.id
		LEFT JOIN clinics c
			   ON u.clinic_id = c.id';
		return $this->db->getArray($query);
	}
}
