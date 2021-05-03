create database Warehouse

-- Ограничение на значение цены (не может быть отрицательной и равной 0)
-- Уникальное значение (название товара)
-- Первичный ключ (код товара)

/* Информация о товаре */
create table Product (
	product_id		int identity(1,1) not null primary key,
	product_name	nvarchar(50) not null unique,
	amount			int not null,
	price			float null check(price > 0),
)


-- Совместное ограничение на значение (столбцы work_phone и home_phone)
-- Первичный ключ (номер поставщика)

/* Информация о поставщиках */
create table Supplier (
	supplier_id		int identity(101,1) not null primary key,
	surname			nvarchar(50) not null,
	work_phone		char(11) null,
	home_phone		char(11) null,
	constraint phone check(work_phone is not null or home_phone is not null)
)


-- Ограничение на значение даты поставки (только будущие)
-- Два внешних ключа (код товара и номер поставщика)

/* Информация о поставке */
create table Delivery (
	product_id		int not null foreign key references Product(product_id),
	supplier_id		int not null foreign key references Supplier(supplier_id),
	delivery_date	date null check(delivery_date > getdate()),
	amount			int not null,
)

-- Уникальное значение (номер поставщика)
-- Внешний ключ (номер поставщика)

/* Местонахождение поставщика */
create table District (
	supplier_id		int not null foreign key references Supplier(supplier_id) unique,
	district		nvarchar(50) not null,
)




insert into Product(product_name, amount, price) values
	('Телевизор', 10, 3.5),
	('Стул', 5, 5),
	('Стол', 13, 5),
	('Часы', 0, 2),
	('Ковёр', 15, 4.5),
	('Клавиатура', 50, 5),
	('Микроволновка', 8, 10),
	('Холодильник', 1, 30),
	('Люстра', 3, 150),
	('Монитор', 5, 10);

insert into Supplier(surname, work_phone, home_phone) values
	('Смирнов', null, 79057626613),
	('Петров', 79067166327, null),
	('Сидоров', 79057626613, null),
	('Моисеев', null, 79047271636),
	('Дубов', 73568920162, null),
	('Семенов', 79047271636, null),
	('Степанов', null, 79048381626),
	('Кириллов', null, 79073719106),
	('Максимов', null, 79036271865),
	('Дорохов', 79047571052, null);

insert into Delivery(product_id, supplier_id, delivery_date, amount) values
	(2, 101, '2021-08-20', 10),
	(1, 102, '2021-08-20', 2),
	(3, 103, '2021-07-05', 3),
	(5, 104, '2021-12-29', 1),
	(6, 105, '2021-12-29', 6),
	(6, 106, '2021-12-29', 7),
	(7, 107, '2021-10-01', 84),
	(8, 108, '2021-05-15', 10),
	(10, 109, '2021-06-10', 5),
	(2, 110, '2021-05-15', 5);

insert into District(supplier_id, district) values
	(101, 'Фрунзенский'),
	(102, 'Бронный'),
	(103, 'Бронный'),
	(104, 'Новый'),
	(105, 'Ленинский'),
	(106, 'Яблочный'),
	(107, 'Малый'),
	(108, 'Новый'),
	(109, 'Жуковский'),
	(110, 'Яблочный');