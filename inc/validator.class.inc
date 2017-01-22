<?php

class Validator {

	const MSG_NOT_INTEGER = 'Некорректное целое число';
	const MSG_NOT_EMAIL = 'Некорректный email';

	public static $lastError;

	public function __construct() {
		self::$lastError = false;
	}

	/**
	 * Проверка на целое число
	 * 
	 * @param string $data
	 * @return boolean
	 */
	public static function isInteger($data) {
		$result = filter_var($data, FILTER_VALIDATE_INT);
		if (!$result) {
			self::$lastError = self::MSG_NOT_INTEGER;
		}
		return $result;
	}

	/**
	 * Проверка на email
	 * 
	 * @param string $data
	 * @return boolean
	 */
	public static function isEmail($data) {
		$result = filter_var($data, FILTER_VALIDATE_EMAIL);
		if (!$result) {
			self::$lastError = self::MSG_NOT_EMAIL;
		}
		return $result;
	}

	public static function isDate($data) {
		$error_message = "Допустима только дата";
		$options = array(
			"options" => array(
				"regexp" => "/\d{4}-\d{2}-\d{2}/"
			)
		);
		if (filter_var($data, FILTER_VALIDATE_REGEXP, $options)) {
			self::$lastError = self::$success;
			return true;
		} else {
			self::$lastError = $error_message;
			return false;
		}
	}

	public static function isNumberOrNull($data) {
		$error_message = "Допустимо использование только натуральных чисел и NULL";
		if (filter_var($data, FILTER_VALIDATE_INT) === 0 || !filter_var($data, FILTER_VALIDATE_INT) === false) {
			self::$lastError = self::$success;
			return true;
		} else {
			if ($data == 0) {
				self::$lastError = self::$success;
				return true;
			} else {
				self::$lastError = $error_message;
				return false;
			}
		}
	}

	public static function isFloat($data) {
		return (filter_var($data, FILTER_VALIDATE_FLOAT)) ? true : false;
	}

	public static function isAge($data) {
		$error_message = "Возраст должен состоять только из&nbsp;цифр в&nbsp;промежутке от&nbsp;1&nbsp;до&nbsp;99.";
		$options = array(
			"options" => array(
				"min_range" => 1,
				"max_range" => 99
			)
		);
		if (filter_var($data, FILTER_VALIDATE_INT, $options)) {
			self::$lastError = self::$success;
			return true;
		} else {
			self::$lastError = $error_message;
			return false;
		}
	}

	public static function isName($data, $min = 2, $max = 30) {
		$error_message = "Имя должно состоять из&nbsp;букв, допустимы пробел и&nbsp;дефис. Длина от&nbsp;2&nbsp;до&nbsp;30&nbsp;символов.";
		$options = array(
			"options" => array(
				"regexp" => "/[^a-zA-ZабвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ\s\-]+/"
			)
		);
		if (filter_var($data, FILTER_VALIDATE_REGEXP, $options)) {
			self::$lastError = $error_message;
			return false;
		} else {
			$count = mb_strlen($data, "UTF-8");
			if ($min <= $count && $count <= $max) {
				self::$lastError = self::$success;
				return true;
			} else {
				self::$lastError = $error_message;
				return false;
			}
		}
	}

	public static function isCategory($data, $min = 2, $max = 30) {
		$error_message = "Название города должно состоять из&nbsp;букв, допустимы цифры, пробел и&nbsp;дефис. Длина от&nbsp;2&nbsp;до&nbsp;30&nbsp;символов.";
		$options = array(
			"options" => array(
				"regexp" => "/[^0-9a-zA-ZабвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ\s\-]+/"
			)
		);
		if (filter_var($data, FILTER_VALIDATE_REGEXP, $options)) {
			self::$lastError = $error_message;
			return false;
		} else {
			$count = mb_strlen($data, "UTF-8");
			if ($min <= $count && $count <= $max) {
				self::$lastError = self::$success;
				return true;
			} else {
				self::$lastError = $error_message;
				return false;
			}
		}
	}

}
