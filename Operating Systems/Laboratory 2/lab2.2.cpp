#include <thread>
#include <iostream>
#include <ctime>


int* A;
int min;
int n;
int status = 0;

int start = 0;
int stop = 0;

void Calculate() {

	std::cout << "\nПоток начал работу - ";
	if (status == 0) {
		start = 0;
		stop = n / 2;
		std::cout << " первая половина" << std::endl;
	}
	if (status == 1) {
		start = n / 2 - 1;
		stop = n;
		std::cout << " вторая половина" << std::endl;
	}
	for (start; start < stop; start++) {
		if (A[start] < min) min = A[start];
	}

	status++;
}

void doWork() {
	std::thread t1(Calculate);
	std::thread t2(Calculate);

	t1.join();
	t2.join();
}


int main() {

	setlocale(LC_ALL, "rus");
	int div;

	std::cout << "Ввести длину - ";
	std::cin >> n;

	A = new int[n];

	srand(time(0));
	std::cout << std::endl;
	for (int i = 0; i < n; i++) {
		A[i] = 1 + rand() % 100;
		std::cout << A[i] << " ";
	}

	min = A[0];
	doWork();

	std::cout << "\nМинимальное число - " << min;
}