(function ($) {
	$(function () {
		$('.js-visit-date').datetimepicker({
			format: 'HH:mm',
			minDate: moment({hour: 8, minute: 00}),
			maxDate: moment({hour: 20, minute: 00}),
			stepping: 15,
			viewDate: false,
		});
	});
})(jQuery);