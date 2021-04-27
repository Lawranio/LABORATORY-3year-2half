/*

вход 1 - сброс сигнала "авария"
вход 2 - датчик верхнего уровня "короткий"
вход 3 - датчик нижнего уровня "длинный"
вход 4 - датчик давления

*/

/*

выход 1 - основной насос
выход 2 - резервный насос
выход 3 - сигнал "авария"

*/

#include <thread>
#include <iostream>
#include "windows.h"

using namespace std;

bool in1, in4 = 0;
bool in2, in3 = 1;				// входы

bool out1, out2, out3 = 0;		// выходы

bool isRunning = false;			// работает ли насос
bool isFailure = false;			// авария ли

int number = 1;					// номер насоса
int counter = 0;				// время симуляции


// Симуляция вводимых значений
void Simulation() {

	cout << "Насосы не работают" << endl << endl;
	Sleep(200);

	// Первое включение насоса
	in2 = 0;
	cout << "Вода ниже короткого" << endl << endl;
	Sleep(200);

	in3 = 0;
	cout << "Вода ниже длинного" << endl << endl;
	Sleep(200);

	in3 = 1;
	cout << "Вода выше длинного" << endl << endl;
	Sleep(200);

	in2 = 1;
	cout << "Вода выше короткого" << endl << endl;
	Sleep(200);


	// Второе включение насоса
	in2 = 0;
	cout << "Вода ниже короткого" << endl << endl;
	Sleep(200);

	// Сброс аварии
	in1 = 1;
	cout << "СБРОС АВАРИИ" << endl << endl;
	in1 = 0;

	in3 = 0;
	cout << "Вода ниже длинного" << endl << endl;
	Sleep(200);

	in3 = 1;
	cout << "Вода выше длинного" << endl << endl;
	Sleep(200);

	in2 = 1;
	cout << "Вода выше короткого" << endl << endl;
	Sleep(200);

	cout << "СИМУЛЯЦИЯ ЗАВЕРШЕНА" << endl;
	return;
}


// логика работы макета
int main() {

	setlocale(LC_ALL, "rus");

	/* 
	
	Запуск параллельного потока,
	в котором изменяются входы макета

	*/
	thread t1(Simulation);

	while (true) {

		if (in2 == 1) {
			cout << "Уровень воды выше верхнего датчика - насосы не работают" << endl << endl;
			out1 = 0;
			out2 = 0;

			in4 = 1;
			isRunning = false;
		}


		if (in3 == 0 && isRunning == false && isFailure == false && number == 1) {
			cout << "Уровень воды ниже нижнего датчика - включается насос 1" << endl << endl;
			out1 = 1;
			number++;

			isRunning = true;
		}


		if (in3 == 0 && isRunning == false && isFailure == false && number == 2) {
			cout << "Уровень воды ниже нижнего датчика - включается насос 2" << endl << endl;
			out1 = 1;
			number--;

			isRunning = true;
		}


		if (in4 == 1 && isFailure == false) {
			cout << "Оба насоса не работают - авария" << endl << endl;
			out3 = 1;
			isFailure = true;
		}


		if (in1 == 1) {
			cout << "Сигнал 'авария' сброшен" << endl << endl;
			out3 = 0;
			isFailure = false;
		}
	}
}