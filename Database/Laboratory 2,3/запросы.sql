-- ��������� ����������� check
insert into Product(product_name, amount, price) values
	('�����', 15, 0)

-- ��������� ������� ������������
insert into Product(product_name, amount, price) values
	('���������', 15, 13)


-- ��������� ����������� ����������� check
insert into Supplier(surname, work_phone, home_phone) values
	('��������', null, null)


-- ��������� ����������� check
insert into Delivery(product_id, supplier_id, delivery_date, amount) values
	(3, 104, '2020-08-20', 15)

-- ��������� ������� ������������
insert into District(supplier_id, district) values
	(102, '�����')

-- �������� ������ �� ������������ ������
delete from Product
where amount = 1

-- �������� ����� �� ���������� �������
delete from District
where district = '�������'