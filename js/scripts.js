$(document).ready(function($) {
	var date = new Date();
	$("#currentYear").html(date.getFullYear());
	$('#myCarousel').carousel({
		interval: 5000
	});

	$('#carousel-text').html($('#slide-content-0').html());
});