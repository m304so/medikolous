(function ($) {
	if ($(document).height() <= $(window).height()) {
		$('footer.footer').addClass('navbar-fixed-bottom');
	}

	$('.js-auth-form').submit(function (event) {
		var data = '{';
		$(this).find('input').each(function () {
			data += '"' + $(this).attr('name') + '":"' + $(this).val() + '",';
		});
		data = data.slice(0, -1) + '}';

		$.ajax({
			method: 'POST',
			url: '/auth/login',
			dataType: 'JSON',
			data: JSON.parse(data)
		}).done(function (answer) {
			if (!answer.result) {
				$('.js-auth-form').children('.form-group').addClass('has-error');
				console.log(answer.error);
			} else {
				$('.js-auth-form').children('.form-group').removeClass('has-error');
				$('.js-auth-form').children('.form-group').addClass('has-success');
				location.reload();
			}
		});
		event.preventDefault();
	});

	$('.js-form-visit-doctor').submit(function (event) {
		var data = '{';
		$(this).find('input').each(function () {
			data += '"' + $(this).attr('name') + '":"' + $(this).val() + '",';
		});
		data = data.slice(0, -1) + '}';

		$.ajax({
			method: 'POST',
			url: '../addVisitor',
			dataType: 'JSON',
			data: JSON.parse(data)
		}).done(function (answer) {
			if (!answer.result) {
				alert('Запись на это время уже существует');
			} else {
				alert('Ваша заявка успешно принята');
			}
		});
		event.preventDefault();
	});

	$('.js-auth-form').keypress(function (event) {
		if (event.which == 13) {
			$('.js-auth-form').submit();
		}
	})

	$('.js-btn-auth').on('click', function () {
		$('.js-auth-form').submit();
	});

})(jQuery);