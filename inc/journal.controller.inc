<?php

require_once 'journal.model.inc';

class JournalController extends mainController {

	private $_model;

	public function __construct() {
		parent::__construct();
		$this->_model = new Journal();
		$assigns = [
			'menu' => 'journal'
		];
		$this->setAssigns($assigns);
	}

	public function index() {
		$journal = $this->_model->getVisitorsAll();
		$assigns = [
			'journal' => $journal,
			'tpl' => 'p-journal-index.tpl'
		];
		$this->setAssigns($assigns);
		$this->showView();
	}
}
