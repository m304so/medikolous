<div class="container">
	<h1>Врачи</h1>
	{foreach from=$doctors key=key item=doctor}
		<div class="col-xs-12 col-sm-12 col-md-12 col-lg-6" style="min-height: 120px; margin-bottom: 20px;">
			<div class="col-xs-12 col-sm-3 col-md-3 col-lg-3">
				<img src="{$doctor.avatar}">
				{if $moderator}
					<button type="button" class="form-control btn-primary js-btn-user-edit" style="font-size: 0.8em; margin-top: 10px;" data-link="/doctor/edit/{$doctor.id}">Редактировать</button>
				{/if}
			</div>
			<div class="col-lg-6 col-sm-10 col-md-10">
				<a href="{$doctor.link}" target="_blank">{$doctor.name}&nbsp;{$doctor.surname}&nbsp;{$doctor.patronymic}</a>
				<br>
				{if $doctor.adultGroup = 1}
					взрослый
				{elseif $doctor.adultGroup = 2}
					детский
				{elseif $doctor.adultGroup = 3}
					взрослый, детский
				{/if}
				<br>
				<a href="{$doctor.clinicName}" style="font-size: 0.8em; color: green;" target="_blank">{$doctor.clinicName}</a>
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

