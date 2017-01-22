(function ($) {
	$('.date-group').hide();
	$('.js-visit-date').datetimepicker({
		format: 'HH:mm',
		minDate: moment({hour: 8, minute: 00}),
		maxDate: moment({hour: 20, minute: 00}),
		stepping: 15,
		viewDate: false,
	});

	$('.js-weekday').on('change', function () {
		var className = $(this).val();
		if (this.checked) {
			$(this).siblings('span').css('font-weight', 'bold');
			$('.js-' + className).show();
		} else {
			$(this).siblings('span').css('font-weight', 'normal');
			$('.js-' + className).children('input').val('');
			$('.js-' + className).hide();
		}
	});
})(jQuery);