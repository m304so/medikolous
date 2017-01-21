<div class="container">
	<h1>Найти врача</h1>
	<!-- Search -->
	<form>
		<div class="col-xs-12 col-md-6 col-lg-4">
			<h3>Специализация</h3>
			<div class="input-group">
				<span class="input-group-addon transparent"><span class="glyphicon glyphicon-education"></span></span>
				<select class="form-control left-border-none" name="speciality">
					<option>любая</option>
				</select>
			</div><br>
			<h3>Время приема</h3>
			<div class="input-group date">
				<span class="input-group-addon transparent"><span class="glyphicon glyphicon-calendar"></span></span>
				<input class="form-control js-visit-date" placeholder="Дата приема" type="text" name="visitdate"/>
			</div>
			<br>
			<div class="form-group">
				<h3>Персональные данные</h3>
				<div class="input-group">
					<span class="input-group-addon transparent"><span class="glyphicon glyphicon-user"></span></span>
					<input class="form-control left-border-none" placeholder="Фамилия" type="text" name="surname">
					<input class="form-control left-border-none" placeholder="Имя" type="text" name="name">
					<input class="form-control left-border-none" placeholder="Отчество" type="text" name="patronymic">
				</div>
				<br>
			</div>
			<br>
			<div class="input-group">
				<span class="input-group-addon transparent"><span class="glyphicon glyphicon-search"></span></span>
				<button class="btn btn-primary active form-control left-border-none">Найти</button>
			</div>
		</div>
		<div class="col-xs-12 col-md-6 col-lg-4">
			{include 'b-doctor-list.tpl'}
		</div>
	</form>
	<!-- /Search -->
</div>

<script type="text/javascript">
	$(function () {
		$('.js-visit-date').datetimepicker();
	});
</script>