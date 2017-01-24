<?php

require_once 'model.class.inc';

class Parser extends Model {

	public function __construct() {
		parent::__construct();
	}

	public function simpleParse($html, $pattern, $key, $name, $tail = false, $revers = false, $debug = false, $num = false) {
		$matches = [];
		preg_match_all($pattern, $html, $matches);
		if ($debug) {
			if (!$num) {
				log::dump($matches);
			} else {
				if (is_int($num)) {
					log::dump($matches[$num]);
				} elseif (is_array($num)) {
					$cnt = sizeof($num);
					for ($i = 0; $i < $cnt; $i++) {
						log::dump($matches[$num[$i]]);
					}
				}
			}
		}
		if (is_int($key)) {
			$count = sizeof($matches[$key]);
			for ($i = 0; $i < $count; $i++) {
				if ($tail) {
					$result[$i] = ($revers) ? $tail . $matches[$key][$i] : $matches[$key][$i] . $tail;
				} else {
					$result[$i] = $matches[$key][$i];
				}
			}
		}
		if (is_array($key)) {
			$count = sizeof($matches[0]);
			for ($i = 0; $i < $count; $i++) {
				$cnt = sizeof($key);
				if (is_array($tail)) {
					for ($j = 0; $j < $cnt; $j++) {
						$result[$i][] = ($revers) ? $tail[$j] . $matches[$key][$i] : $matches[$key][$i] . $tail[$j];
					}
				} else {
					for ($j = 0; $j < $cnt; $j++) {
						if (!empty($matches[$key[$j]][$i])) {
							$result[$i][] = $matches[$key[$j]][$i];
						}
					}
				}
			}
		}

		return [$name => $result];
	}

}
