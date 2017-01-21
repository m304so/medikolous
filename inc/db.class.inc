<?php

class DB {

	private $DBH;
	private $STH;
	private $connection;
	private $options = array(
		PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
		PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC
	);
	private $err_msg = array(
		"background-color" => "#d12e46",
		"color" => "white",
		"padding" => "5px"
	);

	public function __construct() {
		$this->connection = "mysql:host=" . HOST . ";dbname=" . BASE . ";";
		try {
			$this->DBH = new PDO($this->connection, USER, PSWD, $this->options);
			return true;
		} catch (PDOException $e) {
			$this->show_error($e->getMessage());
		}
	}

	// Функция выполняет SQL-запрос
	public function execute($query, $params = null) {
		$this->STH = $this->DBH->prepare($query);
		try {
			$this->STH->execute($params);
			return true;
		} catch (PDOException $e) {
			$this->show_error($e->getMessage());
		}
	}

	// Функция выполняет SQL-запрос
	public function lastID() {
		return $this->DBH->lastInsertId();
	}

	/* Функция возвращает массив по SQL-запросу
	 * или false, если запрос вернул пустой результат
	 */

	public function getArray($query, $params = null) {
		$this->execute($query, $params);
		$array = $this->STH->fetchAll();
		if (!empty($array)) {

			return $array;
		} else {
			return false;
		}
	}

	// Отображение внутренних ошибок
	private function show_error($error) {
		if (isset($this->err_msg) && !empty($this->err_msg)) {
			$style = ' style="';
			foreach ($this->err_msg as $attribute => $value) {
				$style .= $attribute . ':' . $value . ';';
			}
			$style .= '"';
		}
		echo '<div' . $style . '>' . $error . '</div>';
	}

}
