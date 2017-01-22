<div class="container">
	<h1>Редактор врачей</h1>
	{if $isNew}
		<form class="js-form-new-doctor" method="POST">
			<div class="col-xs-12 col-md-6 col-lg-4">
				<h3>Специализация</h3>
				<div class="input-group">
					<span class="input-group-addon transparent"><span class="glyphicon glyphicon-education"></span></span>
					<select class="form-control left-border-none" name="speciality">
						<option>любая</option>
					</select>
				</div><br>
				<h3>Расписание</h3>
				<div class="input-group date">
					<label class="checkbox-inline"><input type="checkbox" class="js-weekday" value="monday"><span>ПН</span></label>
					<label class="checkbox-inline"><input type="checkbox" class="js-weekday" value="tuesday"><span>ВТ</span></label>
					<label class="checkbox-inline"><input type="checkbox" class="js-weekday" value="wednesday"><span>СР</span></label>
					<label class="checkbox-inline"><input type="checkbox" class="js-weekday" value="thursday"><span>ЧТ</span></label>
					<label class="checkbox-inline"><input type="checkbox" class="js-weekday" value="friday"><span>ПТ</span></label>
					<label class="checkbox-inline"><input type="checkbox" class="js-weekday" value="saturday"><span>СБ</span></label>
					<label class="checkbox-inline"><input type="checkbox" class="js-weekday" value="sunday"><span>ВС</span></label>
				</div>
				<div class="mv-15"></div>
				<div class="row">
						<div class="input-group date date-group js-monday">
							<span class="input-group-addon transparent">ПН</span>
							<input class="form-control js-visit-date" placeholder="с" type="text" name="visitdate"/>
							<input class="form-control js-visit-date" placeholder="до" type="text" name="visitdate"/>
						</div>
						<div class="input-group date date-group js-tuesday">
							<span class="input-group-addon transparent">ВТ</span>
							<input class="form-control js-visit-date" placeholder="с" type="text" name="visitdate"/>
							<input class="form-control js-visit-date" placeholder="до" type="text" name="visitdate"/>
						</div>
						<div class="input-group date date-group js-wednesday">
							<span class="input-group-addon transparent">СР</span>
							<input class="form-control js-visit-date" placeholder="с" type="text" name="visitdate"/>
							<input class="form-control js-visit-date" placeholder="до" type="text" name="visitdate"/>
						</div>
						<div class="input-group date date-group js-thursday">
							<span class="input-group-addon transparent">ЧТ</span>
							<input class="form-control js-visit-date" placeholder="с" type="text" name="visitdate"/>
							<input class="form-control js-visit-date" placeholder="до" type="text" name="visitdate"/>
						</div>
						<div class="input-group date date-group js-friday">
							<span class="input-group-addon transparent">ПТ</span>
							<input class="form-control js-visit-date" placeholder="с" type="text" name="visitdate"/>
							<input class="form-control js-visit-date" placeholder="до" type="text" name="visitdate"/>
						</div>
						<div class="input-group date date-group js-saturday">
							<span class="input-group-addon transparent">СБ</span>
							<input class="form-control js-visit-date" placeholder="с" type="text" name="visitdate"/>
							<input class="form-control js-visit-date" placeholder="до" type="text" name="visitdate"/>
						</div>
						<div class="input-group date date-group js-sunday">
							<span class="input-group-addon transparent">ВС</span>
							<input class="form-control js-visit-date" placeholder="с" type="text" name="visitdate"/>
							<input class="form-control js-visit-date" placeholder="до" type="text" name="visitdate"/>
					</div>
				</div>
				<br>
				<div class="form-group">
					<h3>Персональные данные</h3>
					<div class="input-group">
						<span class="input-group-addon transparent"><span class="glyphicon glyphicon-user"></span></span>
						<input class="form-control left-border-none" placeholder="Фамилия" type="text" name="surname">
						<input class="form-control left-border-none" placeholder="Имя" type="text" name="name">
						<input class="form-control left-border-none" placeholder="Отчество" type="text" name="patronymic">
					</div>
					<br>
				</div>
				<br>
				<div class="input-group">
					<span class="input-group-addon transparent"><span class="glyphicon glyphicon-search"></span></span>
					<button class="btn btn-primary active form-control left-border-none">Сохранить</button>
				</div>
			</div>
		</form>
	{/if}
</div>

<script src="/js/doctor-edit.js"></script>
