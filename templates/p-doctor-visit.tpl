<div class="container">
	<div class="col-xs-12 col-sm-6 col-md-6 col-lg-6" style="min-height: 120px; margin-bottom: 20px;">
		<div class="col-xs-3 col-sm-4 col-md-3 col-lg-3">
			<a href="{$doctor.link}" target="_blank"><img src="{$doctor.avatar}"></a>
		</div>
		<div class="col-xs-12 col-sm-8 col-md-9 col-lg-6">
			<b>{$doctor.name}&nbsp;{$doctor.surname}&nbsp;{$doctor.patronymic}</b>
			<br>
			<i>
				{if $doctor.adultGroup = 1}
					взрослый
				{elseif $doctor.adultGroup = 2}
					детский
				{elseif $doctor.adultGroup = 3}
					взрослый, детский
				{/if}
			</i>
			<br>
			<a href="{$doctor.clinicLink}" style="font-size: 0.8em; color: green;" target="_blank">{$doctor.clinicName}</a>
		</div>
	</div>
	<div class="clearfix"></div>
	<div class="col-xs-12 col-sm-6 col-md-6 col-lg-6">
		<form class="js-form-visit-doctor" method="POST">
			<input type="hidden" value="{$doctor.id}" name="doctorId">
			<div class="form-group">
				<h3>Данные пациента</h3>
				<div class="input-group">
					<span class="input-group-addon transparent"><span class="glyphicon glyphicon-user"></span></span>
					<input class="form-control left-border-none" placeholder="Фамилия" type="text" name="surname">
					<input class="form-control left-border-none" placeholder="Имя" type="text" name="name">
					<input class="form-control left-border-none" placeholder="Отчество" type="text" name="patronymic">
				</div>
				<br>
			</div>
			<div class="input-group date">
				<span class="input-group-addon transparent"><span class="glyphicon glyphicon-calendar"></span></span>
				<input class="form-control js-visit-datetime" placeholder="Дата приема" type="text" name="visitdate"/>
			</div>
			<div class="input-group">
				<span class="input-group-addon transparent"><span class="glyphicon glyphicon-ok"></span></span>
				<button class="btn btn-primary active form-control left-border-none">Записаться</button>
			</div>
		</form>
	</div>
</div>


<script src="/js/doctor.js"></script>
