(function ($) {
	var pageNumber = 0;
	var amount = 0;
	var from = 0;
	
	$('.js-parser-form').submit(function (event) {
		from = parseInt($('.js-from-page').val());
		amount = parseInt($('.js-pages-amount').val());
		parse();
		event.preventDefault();
	});

	function parse() {
		if (pageNumber < (from + amount - 1)) {
			pageNumber++;
			$.ajax({
				method: 'POST',
				url: 'parser/parse',
				dataType: 'JSON',
				data: {
					'pageNumber': pageNumber
				}
			}).done(function (answer) {
				if (!answer.result) {
					$('.js-parser-form').children('.form-group').addClass('has-error');
					console.log(answer.error);
				} else {
					var amountInsert = parseInt($('.js-amount-insert').html());
					var amountUpdate = parseInt($('.js-amount-update').html());
					amountInsert += answer.amountInsert;
					amountUpdate += answer.amountUpdate;
					$('.js-amount-insert').html(amountInsert);
					$('.js-amount-update').html(amountUpdate);
					parse();
				}
			});
		}
	}

	$('.js-parse').on('click', function () {
		parse();
	});
})(jQuery);