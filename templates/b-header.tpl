<head>
<meta charset="utf-8">
<meta name="author" content="Sergey Medvedev (m304so@gmail.com)">
<meta http-equiv="X-UA-Compatible" content="IE=Edge">
<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no">
<link type="image/x-icon" href="../img/favicon.ico" rel="icon">
<link type="image/ico" href="../img/favicon.ico" rel="shortcut icon">

<meta name="description" content="{if $description} {$description} {/if}">
<title>{if $title} {$title} {/if}</title>
  
<!-- JavaScript -->
<script type="text/javascript" src="../js/jquery.min.js"></script>
<script type="text/javascript" src="../js/bootstrap.min.js"></script>

<!-- css stylesheets -->
<link rel="stylesheet" href="../css/bootstrap.min.css">
<link rel="stylesheet" href="../css/styles.css">
</head>

<body>
<!-- Фиксированное верхнее меню -->
<div class="navbar navbar-relative-top navbar-inverse" style="border-radius:0;" role="navigation">
	<div class="container">
		<div class="navbar-header">
			<a class="navbar-brand" href="../">Medikolous</a>
			<button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#b-menu-1">
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
			</button>
		</div>
		<div class="collapse navbar-collapse" id="b-menu-1">
			<ul class="nav navbar-nav navbar-right">
				<li {if $menu == ('Список врачей')} class="active" {/if} ><a href="/speciality">Специальности</a></li>
				<li {if $menu == ('Вход')} class="active" {/if} ><a href="/doctor">Врачи</a></li>
				<li {if $menu == ('Вход')} class="active" {/if} ><a href="/visitor">Посетители</a></li>
				<li {if $menu == ('Вход')} class="active" {/if} ><a href="/search">Поиск</a></li>
				<!--<li class="dropdown">
					<a href="#" class="dropdown-toggle" data-toggle="dropdown"><span class="glyphicon glyphicon-user"></span><b class="caret"></b></a>
					<ul class="dropdown-menu">
						<li><a href="#">Вход</a></li>
						<li><a href="#">Регистрация</a></li>
					</ul>
				</li>-->
			</ul>
		</div> <!-- /.nav-collapse -->
	</div> <!-- /.container -->
</div> <!-- /.navbar -->