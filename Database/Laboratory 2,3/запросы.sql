-- Нарушение ограничения check
insert into Product(product_name, amount, price) values
	('Папка', 15, 0)

-- Нарушение условия уникальности
insert into Product(product_name, amount, price) values
	('Телевизор', 15, 13)


-- Нарушение совместного ограничения check
insert into Supplier(surname, work_phone, home_phone) values
	('Иваньков', null, null)


-- Нарушение ограничения check
insert into Delivery(product_id, supplier_id, delivery_date, amount) values
	(3, 104, '2020-08-20', 15)

-- Нарушение условия уникальности
insert into District(supplier_id, district) values
	(102, 'Малый')

-- Удаление строки из родительской таблцы
delete from Product
where amount = 1

-- Удаление строк из подчинённой таблицы
delete from District
where district = 'Бронный'