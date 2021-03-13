/* ЗАДАНИЕ:

В конец двоичного файла целого типа дописать чётные элементы этого файла

*/

/* СПИСОК ИСКЛЮЧЕНИЙ:

1. Файл не открывается для записи / чтения
2.

*/

#include "binaryRead.h"
#include "binaryWrite.h"

int main()
{
	int array[20];
	int i = 0;

	bin_outstream file_out("binar.dat");
	int data = 3;
	file_out << 2;
	file_out << 5;
	file_out << 4;
	file_out << 12;
	file_out << 11;
	file_out << 1;

	file_out.close();


	bin_instream file("binar.dat");
	int data_2;
	file >> data_2;

	while (!file.eof()) {
		array[i] = data_2;
		i++;
		cout << data_2 << endl;
		file >> data_2;
	}
	file.close();

	cout << endl << endl;

	for (int k = 0; k < i; k++) {
		cout << array[k] << " ";
	}

	bin_outstream file_out_2("binar.dat");
	for (int k = 0; k < i; k++) {
		if (array[k] % 2 == 0) file_out_2 << array[k];
	}
	file_out_2.close();

	bin_instream file_2("binar.dat");
	file_2 >> data_2;

	cout << endl << endl;

	while (!file_2.eof()) {
		array[i] = data_2;
		i++;
		cout << data_2 << endl;
		file_2 >> data_2;
	}
	file_2.close();
}


