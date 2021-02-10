#ifndef IPv4
#define IPv4

#include <iostream>
#include <Windows.h>

using namespace std;

class IP {
public:
	IP();
	IP(int first, int second, int third, int fourth);
	~IP();
	void Print();
	void setIP(int first, int second, int third, int fourth);
	void connectIP();

private:
	bool isSet{ false };
	int* ip;
	int size{ 0 };
	void checkIP();
};

IP::IP() {
	size = 4;
	ip = new int[size];

	try {
		/* Ошибка динамического выделения памяти */
		if (ip == 0) throw ("Error: Free store exhausted");
	}
	catch (const char* error) {
		cerr << error << endl;
		exit(-3);
	}
}

IP::IP(int first, int second, int third, int fourth) {
	size = 4;
	ip = new int[size];

	try {
		/* Ошибка динамического выделения памяти */
		if (ip == 0) throw ("Error: Free store exhausted");
	}
	catch (const char* error) {
		cerr << error << endl;
		exit(-3);
	}

	ip[0] = first;
	ip[1] = second;
	ip[2] = third;
	ip[3] = fourth;
	
	isSet = true;

	try {
		checkIP();
	}
	catch (pair<int, int> &exc) {
		/* Неверные данные октета IP адреса - ожидается диапазон [0..255] */
		cerr << "Error: Incorrect IP. Must be in a range of [0..255], but received "
			<< exc.first << " in octet " << exc.second << "." << endl;
		exit(-1);
	}
}

IP::~IP() {
	delete[] ip;
	ip = NULL;
}

/* Вывод в консоль */
void IP::Print() {
	try {
		if (isSet == false) throw isSet;
	}
	catch (bool isSet) {
		/* Попытка вывести IP адрес в консоль, хотя он ещё не задан */
		cerr << "Error: IP for this client is not set yet. Unable to print it" << endl;
		exit(-2);
	}

	cout << "Client IP: ";
	for (int i = 0; i < 4; i++) {
		cout << ip[i];
		if (i < 3) cout << ".";
	}
	cout << endl;
}


/* Проверка диапазона [0..255] октетов */
void IP::checkIP() {
	int value;
	int octet;
	for (int i = 0; i < 4; i++) {
		if (ip[i] < 0 || ip[i] > 255) {
			value = ip[i];
			octet = i + 1;
			throw make_pair(value, octet);
			break;
		}
	}
}


/* Задание IP адреса пустому объекту 
* 
*  @in param - 4 октета IP адреса
*/
void IP::setIP(int first, int second, int third, int fourth) {
	ip[0] = first;
	ip[1] = second;
	ip[2] = third;
	ip[3] = fourth;

	isSet = true;

	try {
		checkIP();
	}
	catch (pair<int, int>& exc) {
		/* Неверные данные октета IP адреса - ожидается диапазон [0..255] */
		cerr << "Error: Incorrect IP. Must be in a range of [0..255], but received "
			<< exc.first << " in octet " << exc.second << "." << endl;
		exit(-1);
	}
}


/* Подключение по IP адресу */
void IP::connectIP() {
	try {
		/* Невозможно подключиться. IP адрес ещё не задан для этого клиента */
		if (isSet == false) throw ("Error: Unable to connect. IP for this client is not set yet");
	}
	catch (const char* error) {
		cerr << error << endl;
		exit(-4);
	}

	cout << "Establishing a connection with ";
	Print();

	/* Симуляция задержки подключения - чтобы было красиво :) */
	for (int i = 0; i < 4; i++) {
		cout << "." << endl;
		Sleep(400);
	}

	/* Симуляция ошибки подключения */
	try {
		srand(time(0));
		/* Невозможно подключиться к клиенту */
		if (rand() % 3 == 0) throw ("Error: Unexpected behavior occurs. Unable to establish connection");
	}
	catch (const char* error) {
		cerr << error << endl;
		exit(-5);
	}

	cout << endl << "Connected to client" << endl;
}

#endif // !IPv4
