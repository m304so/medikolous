<?php

require_once 'config.php';
require_once 'inc/controller.class.inc';
require_once 'inc/log.class.inc';

if (isset($_GET['request']) && preg_match('/^[\d\w_\/\-]+$/', $_GET['request'])) {
	$request = $_GET['request'];
	$route = explode('/', $request);
	$path = 'inc/' . $route[0] . '.controller.inc';
	if (file_exists($path)) {
		require_once $path;
		$cName = ucfirst($route[0]) . 'Controller';
		$controller = new $cName;
		if (isset($route[1]) && !empty($route[1]) && method_exists($controller, $route[1]) && is_public($controller, $route[1])) {
			call_user_func(array($controller, $route[1]), $route[2]);
		} else {
			call_user_func(array($controller, 'index'));
		}
	}
}

if (!$controller) {
	$controller = new mainController();
	$controller->index();
}

function is_public($class, $method) {
	$result = new ReflectionMethod($class, $method);
	return $result->isPublic();
}
