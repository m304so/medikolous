<div class="container">
	<h1>Специальности</h1>
	{foreach from=$specialties key=category item=items}
		<div class="col-xs-12 col-sm-6 col-md-4 col-lg-4">
			<h4>{$category}</h4>
			<ul class="speciality-list">
				{foreach from=$items item=name}
					<li><a href='#'>{$name.name}</a></li>
				{/foreach}
			</ul>
		</div>
	{/foreach}
</div>


