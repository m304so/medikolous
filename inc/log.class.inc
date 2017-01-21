<?php

class log {

	public static function dump($var = '', $is_print = 1) {
		echo '<pre>';
		$data = print_r($var, 1);
		if ($is_print) {
			print htmlspecialchars($data);
		}
		echo '</pre>';
		return $data;
	}

}
