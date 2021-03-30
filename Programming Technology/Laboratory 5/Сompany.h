#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include "Computer.h"

using namespace std;

class Company {
protected:

	string name;
	string address;
	string phone;
	Computer computer[10];
	int counter{ 0 };
};



//* MANUFACTURER *//

class Manufacturer : public Company {
public:
	Manufacturer(string _name, string _address, string _phone) {
		name = _name;
		address = _address;
		phone = _phone;
	}
	~Manufacturer() = default;

	/* Продать компьютер дистрибьютору */
	Computer SellComputer() {
		int temp = counter;
		counter--;
		return computer[temp];
	}

	/* Создать компьютер */
	void CreateComputer() {
		cout << "Computer created by manufacturer: " << this->name << endl;
		Computer item;
		item.SetParam();
		computer[counter] = item;
		counter++;
	}
};



//* DISTRIBUTOR *//

class Distributor : public Company {
public:
	Distributor(string _name, string _address, string _phone) {
		name = _name;
		address = _address;
		phone = _phone;
	}
	~Distributor() = default;

	/* Продать компьютер */
	Computer SellComputer() {
		cout << "Computer sold by distributor: " << this->name << endl;
		int temp = counter;
		counter--;
		return computer[temp];
	}

	/* Получить компьютер у производителя */
	void GetComputer(Manufacturer &item) {
		cout << "Computer got by distributor: " << this->name << endl;
		computer[counter] = item.SellComputer();
		counter++;
	}
};
#endif // !COMPANY_H
