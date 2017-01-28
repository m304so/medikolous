<div class="container">
	<h1>Врачи</h1>
	{foreach from=$doctors key=key item=doctor}
		<div class="col-xs-12 col-sm-6 col-md-6 col-lg-6" style="min-height: 120px; margin-bottom: 20px;">
			<div class="col-xs-3 col-sm-4 col-md-3 col-lg-3">
				<a href="{$doctor.link}" target="_blank"><img src="{$doctor.avatar}"></a>
					{if $moderator}
					<button type="button" class="form-control btn-primary js-btn-user-edit"  style="margin-left: -20px; width: 120px;" data-link="/doctor/editor/{$doctor.id}">Редактировать</button>
				{else}
					<button type="button" class="form-control btn-primary js-btn-link-open" style="margin-left: -15px; width: 110px;" data-link="/doctor/visit/{$doctor.id}">Записаться</button>
				{/if}
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
	{/foreach}
</div>

{if $moderator}
	<script>
		(function ($) {
			$('.js-btn-user-edit').on('click', function () {
				location.href = $(this).data('link');
			});
		})(jQuery)
	</script>
{/if}

<script src="/js/doctor.js"></script>