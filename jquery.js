$(function() {
		$('.code-hover').hover(
			function(){
				$(this).find('.link').addClass('btn-active');
			},
			function(){}
		);
});
