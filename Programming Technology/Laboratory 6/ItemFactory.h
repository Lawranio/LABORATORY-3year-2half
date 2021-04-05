// ItemFactory.h: interface for the ItemFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ITEMFACTORY_H__E790A7FC_2B98_4187_972E_E33B95B5C143__INCLUDED_)
#define AFX_ITEMFACTORY_H__E790A7FC_2B98_4187_972E_E33B95B5C143__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Book.h"
#include "Journal.h"
//
// Фабрика печатных изданий
//
class ItemFactory
{
public:
	// Фабричный метод для создания экземпляра книги.
	// За уничтожение объекта отвечает клиент.
	Journal* CreateJournal();

	// Фабричный метод для создания экземпляра журнала.
	// За уничтожение объекта отвечает клиент.
	Book* CreateBook();

	// Вернуть ссылку на экземпляр "одиночки", который и есть экземпляр фабрики.
	static ItemFactory& Instance();

	virtual ~ItemFactory();

private:

	// Единственный экземпляр "одиночки" - статическое поле
	static ItemFactory s_instance;

	// Счетчик созданных "продуктов" - печатных изданий.
	// Это поле объекта (не статическое поле). Оно предназначено для генерации
	// искусственных экземпляров печатных изданий.
	int _counter;

	// Закрытый конструктор для того, чтобы клиенты класса не могли создавать
	// экзепляры фабрики. Так реализуется шаблон проектирования "одиночка".
	ItemFactory();

};





// Инициализация статического поля класса,
// для него будет вызыван конструктор без параметров
ItemFactory ItemFactory::s_instance;

ItemFactory::ItemFactory() : _counter(0)
{
}

ItemFactory::~ItemFactory()
{

}

ItemFactory& ItemFactory::Instance()
{
	return s_instance;
}

Book* ItemFactory::CreateBook()
{
	_counter++;

	// Преобразование числа в строку
	char buffer[10];
	_itoa_s(_counter, buffer, 10);

	const string title = string("Краткое руководство по С++. Том ") + string(buffer);
	const double price = _counter;
	string author = string("Страуструп Б.");

	return new Book(title, price, author);
}

Journal* ItemFactory::CreateJournal()
{
	_counter++;

	// Преобразование числа в строку
	char buffer[5];
	_itoa_s(_counter, buffer, 5);

	string title = string("Мурзилка");
	double price = _counter;
	string volume = string(buffer);

	return new Journal(title, price, volume);

}

#endif // !defined(AFX_ITEMFACTORY_H__E790A7FC_2B98_4187_972E_E33B95B5C143__INCLUDED_)
