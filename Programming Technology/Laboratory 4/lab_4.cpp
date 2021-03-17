/* ЗАДАНИЕ:

В конец двоичного файла целого типа дописать чётные элементы этого файла

*/

/* СПИСОК ИСКЛЮЧЕНИЙ:

1. Файл не открывается
2. Ошибка при работе с файлом

*/

#include "binaryRead.h"
#include "binaryWrite.h"
#include "Institute_Worker.h"
#include <vector>

void processData(vector<int> data, const char* path) {
	int tempV[100];
	int temp;
	int i = 0;

	/* Запись в файл */
	bin_outstream fout(path);
	for (int k = 0; k < data.size(); k++) {
		fout << data[k];
	}
	fout.close();


	/* Чтение из файла */
	bin_instream fin(path);
	fin >> temp;
	while (!fin.eof()) {
		tempV[i] = temp;
		i++;
		cout << temp << " ";
		fin >> temp;
	}
	fin.close();


	cout << endl;


	/* Дописывание в файл */
	bin_outstream fout2(path);
	for (int k = 0; k < i; k++) {
		if (tempV[k] % 2 == 0) fout2 << tempV[k];
	}
	fout2.close();

	cout << endl;


	/* Проверка: считывание из файла */
	i = 0;
	bin_instream fin2(path);
	fin2 >> temp;
	while (!fin2.eof()) {
		tempV[i] = temp;
		i++;
		cout << temp << " ";
		fin2 >> temp;
	}
	fin2.close();
}


int main()
{
	vector<int> q;
	q.push_back(3);
	q.push_back(1);
	q.push_back(6);
	q.push_back(12);
	q.push_back(52);
	q.push_back(0);


	processData(q, "text.dat");

	instituteWorker a("abc", "dep_a", "pos1", 2000, 12, 100);
	instituteWorker b("xyz", "dep_b", "pos2", 1962, 15, 12.1);

	vector<instituteWorker> r;
	vector<instituteWorker> e;
	r.push_back(a);
	r.push_back(b);

	//writeData("text.dat", r);
	//readData("text.dat", e);

	/*for (int i = 0; i < e.size(); i++) {
		cout << e[i];
	}*/
}




