<head>
	<meta charset="utf-8">
	<meta name="author" content="Sergey Medvedev (m304so@gmail.com)">
	<meta http-equiv="X-UA-Compatible" content="IE=Edge">
	<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no">
	<link type="image/x-icon" href="/img/favicon.ico" rel="icon">
	<link type="image/ico" href="/img/favicon.ico" rel="shortcut icon">

	<meta name="description" content="{if $description} {$description} {/if}">
	<title>{if $title} {$title} {/if}</title>

	<!-- JavaScript -->
	<script type="text/javascript" src="/js/jquery.min.js"></script>
	<script type="text/javascript" src="/js/bootstrap.min.js"></script>
	<script type="text/javascript" src="/js/moment.js"></script>
	<script type="text/javascript" src="/js/bootstrap-datetimepicker.min.js"></script>

	<!-- css stylesheets -->
	<link rel="stylesheet" href="/css/bootstrap.min.css">
	<link rel="stylesheet" href="/css/bootstrap-datetimepicker.min.css">
	<link rel="stylesheet" href="/css/styles.css">
</head>

<body>
	<!-- Фиксированное верхнее меню -->
	<div class="navbar navbar-relative-top navbar-inverse" style="border-radius:0;" role="navigation">
		<div class="container">
			<div class="navbar-header">
				<a class="navbar-brand" href="/">{$logo}</a>
				<button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#menu-top">
					<span class="icon-bar"></span>
					<span class="icon-bar"></span>
					<span class="icon-bar"></span>
				</button>
			</div>
			<div class="collapse navbar-collapse" id="menu-top">
				<ul class="nav navbar-nav navbar-right">
					<li {if $menu == ('search')} class="active" {/if} ><a href="/search">Поиск</a></li>
					{if $moderator}
						<li class="dropdown">
							<a href="#" class="dropdown-toggle" data-toggle="dropdown">Специальности<b class="caret"></b></a>
							<ul class="dropdown-menu">
								<li><a href="/speciality">Список специальностей</a></li>
								<li><a href="/speciality/addNew">Добавить новую</a></li>
							</ul>
						</li>
						<li class="dropdown">
							<a href="#" class="dropdown-toggle" data-toggle="dropdown">Врачи<b class="caret"></b></a>
							<ul class="dropdown-menu">
								<li><a href="/doctor">Реадактор</a></li>
								<li><a href="/doctor/addNew">Добавить нового</a></li>
							</ul>
						</li>
						<li {if $menu == ('journal')} class="active" {/if} ><a href="/journal">Журнал записей</a></li>
						<li {if $menu == ('parser')} class="active" {/if} ><a href="/parser">Парсер</a></li>
					{else}
						<li {if $menu == ('doctors')} class="active" {/if} ><a href="/doctor">Врачи</a></li>
						<li {if $menu == ('speciality')} class="active" {/if} ><a href="/speciality">Специальности</a></li>
					{/if}
					{if !$login}
						<li class="dropdown">
							<a href="#" class="dropdown-toggle" data-toggle="dropdown"><span class="glyphicon glyphicon-user"></span><b class="caret"></b></a>
							<ul class="dropdown-menu">
								<li><a href="#" data-toggle="modal" data-target="#auth">Вход</a></li>
								<li><a href="#" data-toggle="modal" data-target="#reg">Регистрация</a></li>
							</ul>
						</li>
					{else}
						<li><a href="/auth/logout">Выход</a></li>
						{/if}
				</ul>
			</div> <!-- /.nav-collapse -->
			{include 'b-auth.tpl'}
		</div> <!-- /.container -->
	</div> <!-- /.navbar -->
