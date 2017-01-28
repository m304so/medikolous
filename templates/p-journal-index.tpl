<div class="container">
	{foreach from=$journal key=key item=visitor}
		<div class="col-xs-12 col-sm-6 col-md-6 col-lg-6">
			<h3>{$visitor.surname}&nbsp;{$visitor.name}&nbsp;{$visitor.patronymic}</h3>
			Дата приема: <b>{$visitor.dt_visit}</b><br>
			Врач: <a href="{$visitor.link}" target="_blank">{$visitor.doctorName}&nbsp;{$visitor.doctorSurname}&nbsp;{$visitor.doctorPatronymic}</a><br>
			<a href="{$visitor.clinicLink}" style="font-size: 0.8em; color: green;" target="_blank">{$visitor.clinicName}</a>
		</div>
		<div class="clearfix"></div>
	{/foreach}
</div>

