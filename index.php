<?php

require_once 'config.php';
require_once 'inc/controller.class.inc';
require_once 'inc/log.class.inc';

$request = htmlspecialchars($_GET['request'], ENT_QUOTES);

if ($request) {
	$route = explode('/', $request);
	$path = 'inc/' . $route[0] . '.controller.inc';
	if (file_exists($path)) {
		require_once $path;
		$cName = ucfirst($route[0]) . 'Controller';
		$controller = new $cName;
		if (method_exists($controller, $route[1])) {
			call_user_func(array($controller, $route[1]));
		} else {
			call_user_func(array($controller, 'index'));
		}
	}
}

if (!$controller) {
	$controller = new mainController();
	$controller->index();
}