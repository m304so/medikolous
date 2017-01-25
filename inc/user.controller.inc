<?php

require_once 'parser.model.inc';
require_once 'user.model.inc';

class UserController extends mainController {

	private $_model;

	public function __construct() {
		$this->_model = new User();
	}

	/**
	 * Главная страница парсера
	 * @return void
	 */
	public function index() {
		$assigns = [
			'tpl' => 'p-user-index.tpl'
		];
		$this->setAssigns($assigns);
		$this->showView();
	}

}
