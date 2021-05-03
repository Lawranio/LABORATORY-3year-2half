#include "Library.h"
#include "PurchaseCheapStrategy.h"
#include "PurchaseExpensiveStrategy.h"
#include "PurchaseNewspaperStrategy.h"
#include "PublicLibraryStrategy.h"
#include "UniversityLibraryStrategy.h"
#include "Student.h"
#include "Lecturer.h"
#include "Engineer.h"
#include "ItemFactory.h"
#include <windows.h>
#include  "LibraryItem.h"
#include <iostream>
#include "Book.h"
#include "Journal.h"
#include <locale.h>


using namespace std;
//
// Показать состояние библиотеки и книг в ней
//
void Show(Library& lib);


int main()
{
	setlocale(LC_ALL, "Russian");
	//
	// Библиотеки с различными стратегиями
	//
	Library vlsuLibrary(
		string("Библиотека ВЛГУ"),
		new PurchaseCheapStrategy(15),
		new UniversityLibraryStrategy(50));
	Library regionLibrary(
		string("Региональная библиотека"),
		new PurchaseNewspaperStrategy,
		new PublicLibraryStrategy(65, 40, 30));

	//
	// Читатели разлчиных категорий
	//
	Student st1(string("Петров"), 1);
	Student st2(string("Иванов"), 4);
	Student st3(string("Сидоров"), 5);

	Lecturer lec1(string("Кутузов"), string("доцент"));
	Lecturer lec2(string("Суворов"), string("ассистент"));

	Engineer eng1("Кузнецов", "практикант");
	Engineer eng2("Сталин", "главный инженер");

	//
	// Регистрируем читателей в библиотеках. Некоторые из читателей -
	// в нескольких библиотеках
	//
	vlsuLibrary.AddReader(&st1);
	vlsuLibrary.AddReader(&st2);
	regionLibrary.AddReader(&st3);
	regionLibrary.AddReader(&eng1);
	vlsuLibrary.AddReader(&eng2);

	vlsuLibrary.AddReader(&lec1);
	vlsuLibrary.AddReader(&lec2);
	regionLibrary.AddReader(&lec1);
	regionLibrary.AddReader(&lec2);


	//
	// Генерировать несколько печатных изданий и "продать" их библиотекам
	//
	for (int i = 0; i < 20; i++)
	{
		IItem* item;

		// В половине случаев (i - четное) будем создавать журналы,
		// в половине - книги
		if (i % 2 == 0)
		{
			// Создать экземпляр журнала
			item = ItemFactory::Instance().CreateJournal();
			item = ItemFactory::Instance().CreateNewspaper();
		}
		else
		{
			// Создать экземпляр книги
			item = ItemFactory::Instance().CreateBook();
		}

		//
		// Библиотеки поочередно пытаются закупить печатное издание
		//
		bool isSold = false;

		if (!isSold)
		{
			isSold = vlsuLibrary.PurchaseItem(item);
		}
		if (!isSold)
		{
			isSold = regionLibrary.PurchaseItem(item);
		}

		//
		// Если экземпляр не куплен, надо его уничтожить, чтобы не было
		// мусора (в динамической памяти, а не в прямом смысле)
		//
		if (!isSold)
		{
			delete item;
		}

	}

	//
	// Моделируем выдачу печатных изданий читателям
	//
	vlsuLibrary.LetLibItemOut(vlsuLibrary.GetLibItems()[0], &st1);
	vlsuLibrary.LetLibItemOut(vlsuLibrary.GetLibItems()[1], &lec1);
	vlsuLibrary.LetLibItemOut(vlsuLibrary.GetLibItems()[2], &lec2);
	vlsuLibrary.LetLibItemOut(vlsuLibrary.GetLibItems()[3], &eng2);

	regionLibrary.LetLibItemOut(regionLibrary.GetLibItems()[0], &lec2);
	regionLibrary.LetLibItemOut(regionLibrary.GetLibItems()[1], &lec2);
	regionLibrary.LetLibItemOut(regionLibrary.GetLibItems()[2], &lec1);
	regionLibrary.LetLibItemOut(regionLibrary.GetLibItems()[3], &lec1);
	regionLibrary.LetLibItemOut(regionLibrary.GetLibItems()[4], &eng1);

	//
	// Показать состояние библиотек и книг
	//

	Show(vlsuLibrary);
	Show(regionLibrary);

	return 0;
}



void Show(Library& lib)
{
	//
	// Сведения о библиотеке
	//
	cout << "\n" << "Название библиотеки: " << lib.GetName() << endl;

	//
	// Сведения о всех читателях библиотеки
	//
	cout << "\n" << "Читатели:" << endl;
	vector<Reader*> readers = lib.GetReaders();
	for (int iReader = 0; iReader < readers.size(); iReader++)
	{
		cout << iReader << ") " << readers[iReader]->GetName() << endl;
	}


	//
	// Сведения о книгах
	//
	cout << "\n" << "Экземпляры:" << endl;
	vector<LibraryItem*> items = lib.GetLibItems();
	for (int i = 0; i < items.size(); i++)
	{
		cout << i + 1 << ") " << items[i]->GetTitle();

		// Вывести информацию, специфическую для конкретного типа издания
		Book* book = dynamic_cast<Book*>(items[i]->GetItem());
		Journal* journal = dynamic_cast<Journal*>(items[i]->GetItem());

		if (book != NULL)
		{
			cout << " автор " << book->GetAuthor();
		}
		else
		{
			if (journal != NULL)
			{
				cout << " номер " << journal->GetVolume();
			}
		}

		if (items[i]->GetReader() != NULL)
		{
			cout << " на руках: "
				<< items[i]->GetReader()->GetName()
				<< " на " << items[i]->GetHoldPeriod() << " дней"
				<< endl;
		}
		else
		{
			cout << " на полке" << endl;
		}

		cout
			<< "Инв.№ " << items[i]->GetInventoryNumber()
			<< " Стоимость " << items[i]->GetPrice()
			<< endl;

	}
}
