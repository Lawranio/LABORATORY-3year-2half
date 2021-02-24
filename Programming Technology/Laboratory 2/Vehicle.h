#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

using namespace std;

class Vehicle {
public:
	Vehicle() : model("NULL"), hp(0), price(0.0) {};
	Vehicle(const char* model, int hp, float price);
	~Vehicle() = default;
	void Print();
	void Input(const char* model, int hp, float price);

	friend ostream& operator<< (ostream& out, const Vehicle& item) {
		cout << item.model << " information: " << endl;
		cout << "--horse power: " << item.hp << endl;
		cout << "--price: " << item.price << endl << endl;

		return out;
	}

private:
	const char* model;		// марка
	int hp;			// мощность
	float price;	// стоимость
};






Vehicle::Vehicle(const char* model, int hp, float price) {
	this->model = model;
	this->hp = hp;
	this->price = price;
}


void Vehicle::Print() {
	cout << model << " information: " << endl;
	cout << "--horse power: " << hp << endl;
	cout << "--price: " << price << endl << endl;
}


void Vehicle::Input(const char* model, int hp, float price) {
	this->model = model;
	this->hp = hp;
	this->price = price;
}
#endif // !VEHICLE_H
