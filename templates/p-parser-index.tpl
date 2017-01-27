<div class="container">
	<!-- Parser -->
	<h1>Парсер</h1>
	<form class="js-parser-form" method="POST">
		<div class="col-xs-3 col-md-3 col-lg-3">
			<h3>Стартовая страница</h3>
			<div class="input-group">
				<span class="input-group-addon transparent"><span class="glyphicon glyphicon-home"></span></span>
				<input type="number" class="form-control js-from-page" name="from-page" placeholder="Номер страницы" min="0" value="0"/>
			</div>
			<h3>Количество</h3>
			<div class="input-group date">
				<span class="input-group-addon transparent"><span class="glyphicon glyphicon-piggy-bank"></span></span>
				<input type="number" class="form-control js-pages-amount" name="pages-amount" placeholder="Сколько страниц" min="1" value="1"/>
			</div>
			<br><br>
			<div class="input-group">
				<span class="input-group-addon transparent"><span class="glyphicon glyphicon-save-file"></span></span>
				<button class="btn btn-primary active form-control left-border-none js-parse">Разобрать</button>
			</div>
		</div>
	</form>
	<div class="col-xs-12 col-md-6 col-lg-4">
		<h3>Информация</h3>
		<div class="js-title-update">
			<b>URL http://napopravku.ru/doctors/...PAGEN_1=<span class="js-amount-pages">0</span>
		</div>
		<div class="js-title-insert">
			<b>Добавлено пользователей:</b>&nbsp;<span class="js-amount-insert">0</span>
		</div>
		<div class="js-title-update">
			<b>Обновлено пользователей:</b>&nbsp;<span class="js-amount-update">0</span>
		</div>
	</div>
	<!-- /Parser -->
</div>
<script type="text/javascript" src="../js/parser.js"></script>