<?php

require_once 'auth.model.inc';
require 'validator.class.inc';

class AuthController extends mainController {

	private $_model;

	public function __construct() {
		parent::__construct();
		$this->_model = new Auth();
	}

	/**
	 * TODO: исправить временное решение по авторизации пользователей
	 */
	public function login() {
		$this->redirect(!$this->isAjax());
		if (Validator::isEmail($_POST['email'])) {
			$pwdCheck = sha1('admin');
			if ($_POST['email'] === 'admin@mail.ru') {
				if (sha1($_POST['password']) === $pwdCheck) {
					$_SESSION['login'] = true;
					$_SESSION['access_level'] = 7;
					$answer = ['result' => true];
					$this->jsonReturn($answer);
				}
			}
			$pwdCheck = sha1('moderator');
			if ($_POST['email'] === 'moderator@mail.ru') {
				if (sha1($_POST['password']) === $pwdCheck) {
					$_SESSION['login'] = true;
					$_SESSION['access_level'] = 3;
					$answer = ['result' => true];
					$this->jsonReturn($answer);
				}
			}
		}
		$answer = [
			'result' => false,
			'error' => 'Неверно ввевден логин или пароль'
		];
		$this->jsonReturn($answer);
	}

	public function logout() {
		session_destroy();
		$this->redirect();
	}

}
