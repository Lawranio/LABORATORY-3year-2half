create database Warehouse

-- ����������� �� �������� ���� (�� ����� ���� ������������� � ������ 0)
-- ���������� �������� (�������� ������)
-- ��������� ���� (��� ������)

/* ���������� � ������ */
create table Product (
	product_id		int identity(1,1) not null primary key,
	product_name	nvarchar(50) not null unique,
	amount			int not null,
	price			float null check(price > 0),
)


-- ���������� ����������� �� �������� (������� work_phone � home_phone)
-- ��������� ���� (����� ����������)

/* ���������� � ����������� */
create table Supplier (
	supplier_id		int identity(101,1) not null primary key,
	surname			nvarchar(50) not null,
	work_phone		char(11) null,
	home_phone		char(11) null,
	constraint phone check(work_phone is not null or home_phone is not null)
)


-- ����������� �� �������� ���� �������� (������ �������)
-- ��� ������� ����� (��� ������ � ����� ����������)

/* ���������� � �������� */
create table Delivery (
	product_id		int not null foreign key references Product(product_id),
	supplier_id		int not null foreign key references Supplier(supplier_id),
	delivery_date	date null check(delivery_date > getdate()),
	amount			int not null,
)

-- ���������� �������� (����� ����������)
-- ������� ���� (����� ����������)

/* ��������������� ���������� */
create table District (
	supplier_id		int not null foreign key references Supplier(supplier_id) unique,
	district		nvarchar(50) not null,
)




insert into Product(product_name, amount, price) values
	('���������', 10, 3.5),
	('����', 5, 5),
	('����', 13, 5),
	('����', 0, 2),
	('����', 15, 4.5),
	('����������', 50, 5),
	('�������������', 8, 10),
	('�����������', 1, 30),
	('������', 3, 150),
	('�������', 5, 10);

insert into Supplier(surname, work_phone, home_phone) values
	('�������', null, 79057626613),
	('������', 79067166327, null),
	('�������', 79057626613, null),
	('�������', null, 79047271636),
	('�����', 73568920162, null),
	('�������', 79047271636, null),
	('��������', null, 79048381626),
	('��������', null, 79073719106),
	('��������', null, 79036271865),
	('�������', 79047571052, null);

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
	(101, '�����������'),
	(102, '�������'),
	(103, '�������'),
	(104, '�����'),
	(105, '���������'),
	(106, '��������'),
	(107, '�����'),
	(108, '�����'),
	(109, '���������'),
	(110, '��������');