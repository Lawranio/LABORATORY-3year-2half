/* ЗАДАНИЕ:

Дан файл, элементы которого являются действительными числами. Найти:

1. наибольшее из значений элементов;
2. наименьшее из значений элементов с чётными номерами;
3. наибольшее из значений модулей компонентов с нечётными номерами;
4. сумма наибольшего и наименьшего из значений элементов;
5. разность первого и последнего элемента.



Сформировать массив на диске, содержащий сведения о сотрудниках института.
Структурный тип содержит поля: фамилия, название отдела, год рождения,
                               стаж работы, должность, оклад.
Написать программу, которая выводит в консоль:

1. список сотрудников пенсионного возраста;
2. средний стаж сотрудников в отделе.

*/


/* СПИСОК ИСКЛЮЧЕНИЙ: 

1. Файл не открывается
2. Попытка вывести результаты при ошибке открытия файла

*/

#include "File_Handler.h"
#include "Institute_Worker.h"


int main()
{
    /*fileHandler r("text.txt", 15);
    r.printResult();
    cout << endl << endl;*/

    instituteWorker a("q", "dep_a", "pos_1", 1980, 10, 1);
    instituteWorker b("j", "dep_b", "pos_2", 1960, 10, 12);
    instituteWorker c("l", "dep_c", "pos_3", 2000, 10, 13);
    instituteWorker d("i", "dep_b", "pos_4", 1965, 10, 14);
    instituteWorker e("r", "dep_e", "pos_5", 1940, 10, 15);
    instituteWorker f("t", "dep_b", "pos_6", 1956, 10, 16);

    vector<instituteWorker> q;

    vector<instituteWorker> aggg;

    q.push_back(a);
    q.push_back(b);
    q.push_back(c);
    q.push_back(d);
    q.push_back(e);
    q.push_back(f);

    //listRetirmentAge(q);
    float abc = averageWorkExp(q, "dep_b");
    //cout << abc;

    writeData("text.txt", q);
    readData("text.txt", aggg);

    for (int i = 0; i < aggg.size(); i++) {
        cout << aggg[i];
    }

    return 0;
}
