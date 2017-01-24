{$body}
<script>
	(function ($) {
		function saveNew() {
			$.ajax({
				url: "/parser/saveNewDoctor",
				method: "POST",
				data: {
					'name': 'тест',
					'surname': 'тест',
					'patronymic': 'тест',
					'speciality': 'тест',
				}
			}).done(function (answer) {
				console.log(answer);
			});
		}
		//saveNew();
		$('.item-info').each(function () {
			console.log($(this));
			
			/*
			var str = $(this).get(0).innerText;
			var pos = str.indexOf("\n");
			var doctor = str.substr(0, pos);
			var doctor = str.split(' ');

			var name = doctor[0];
			var surname = doctor[1];
			var patronymic = doctor[2];
			doctor[3] = doctor[3].split("\n");
			doctor[6] = doctor[6].split("\n");
			if (doctor[3][0] != 'стаж') {
				var speciality = (doctor[3][3] == 'детский') ? 'детский ' + doctor[3][1] : doctor[3][1];
			} else {
				var speciality = (doctor[6][3] == 'детский') ? 'детский ' + doctor[6][1] : doctor[6][1];
			}
			console.log(log);
			console.log(sendData);
			*/



		});
	})(jQuery);
</script>