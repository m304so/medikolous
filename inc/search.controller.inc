<?php

require_once 'search.model.inc';
require_once 'doctor.model.inc';

class SearchController extends mainController {

	private $_model;

	public function __construct() {
		parent::__construct();
		$this->_model = new Search();
	}

	public function index() {
		$assigns = [
			'menu' => 'search',
			'doctors' => $doctors,
			'tpl' => 'p-search-index.tpl'
		];
		$this->setAssigns($assigns);
		$this->showView();
	}

}
