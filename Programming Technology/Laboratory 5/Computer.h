#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <string>

using namespace std;

class Computer {
public:
	Computer() = default;
	~Computer() = default;

	void SetParam() {
		cout << "Architecture: ";
		cin >> architecture;

		cout << "Clock frequency: ";
		cin >> frequency;

		cout << "RAM capacity: ";
		cin >> RAMcapacity;

		cout << "HDD capacity: ";
		cin >> HDDcapacity;

		cout << "Price: ";
		cin >> price;

		cout << "Release date: ";
		cin >> release;

		cout << endl << endl;
	}
	float GetPrice() { return price; };


private:
	int architecture{ 0 };
	float frequency{ 0 };
	int RAMcapacity{ 0 };
	int HDDcapacity{ 0 };
	float price{ 0 };
	string release;
};

#endif // !COMPUTER_H
