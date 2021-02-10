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
		/* ������ ������������� ��������� ������ */
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
		/* ������ ������������� ��������� ������ */
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
		/* �������� ������ ������ IP ������ - ��������� �������� [0..255] */
		cerr << "Error: Incorrect IP. Must be in a range of [0..255], but received "
			<< exc.first << " in octet " << exc.second << "." << endl;
		exit(-1);
	}
}

IP::~IP() {
	delete[] ip;
	ip = NULL;
}

/* ����� � ������� */
void IP::Print() {
	try {
		if (isSet == false) throw isSet;
	}
	catch (bool isSet) {
		/* ������� ������� IP ����� � �������, ���� �� ��� �� ����� */
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


/* �������� ��������� [0..255] ������� */
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


/* ������� IP ������ ������� ������� 
* 
*  @in param - 4 ������ IP ������
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
		/* �������� ������ ������ IP ������ - ��������� �������� [0..255] */
		cerr << "Error: Incorrect IP. Must be in a range of [0..255], but received "
			<< exc.first << " in octet " << exc.second << "." << endl;
		exit(-1);
	}
}


/* ����������� �� IP ������ */
void IP::connectIP() {
	try {
		/* ���������� ������������. IP ����� ��� �� ����� ��� ����� ������� */
		if (isSet == false) throw ("Error: Unable to connect. IP for this client is not set yet");
	}
	catch (const char* error) {
		cerr << error << endl;
		exit(-4);
	}

	cout << "Establishing a connection with ";
	Print();

	/* ��������� �������� ����������� - ����� ���� ������� :) */
	for (int i = 0; i < 4; i++) {
		cout << "." << endl;
		Sleep(400);
	}

	/* ��������� ������ ����������� */
	try {
		srand(time(0));
		/* ���������� ������������ � ������� */
		if (rand() % 3 == 0) throw ("Error: Unexpected behavior occurs. Unable to establish connection");
	}
	catch (const char* error) {
		cerr << error << endl;
		exit(-5);
	}

	cout << endl << "Connected to client" << endl;
}

#endif // !IPv4
