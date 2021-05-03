// LibraryItem.h: interface for the LibraryItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIBRARYITEM_H__A4915813_7738_4B67_82F1_17BA66EA451F__INCLUDED_)
#define AFX_LIBRARYITEM_H__A4915813_7738_4B67_82F1_17BA66EA451F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IItem.h"
#include "Reader.h"

//
// Декоратор для единицы хранения. 
// Добавляет структуру и поведение необходимые для использования
// классом библиотека: инвентарный номер, ссылку на читателя, 
//
class LibraryItem : IItem
{
public:
	IItem* GetItem();

	int GetInventoryNumber() const
	{
		return _inventoryNumber;
	}

	int GetHoldPeriod() const
	{
		return _holdPeriod;
	}

	void SetHolderPeriod(int holdPeriod)
	{
		_holdPeriod = holdPeriod;
	}

	// Вернет NULL, если книга - в библиотеке
	Reader* GetReader()
	{
		return _reader;
	}

	// Установить владельца единицы хранения. Если нужно указать, 
	// единица хранения находится в библиотеке, то надо установить
	// значение NULL
	void SetReader(Reader* reader)
	{
		_reader = reader;
	}

	// При создании декоратора печатного издания, сразу же 
	// надо присвоить ему инвентарный номер.
	LibraryItem(IItem* item, int inventoryNumber);

	//
	// При уничтожении декоратора надо уничтожить и "обернутый" объект
	// иначе он будет создавать "мусор" в памяти
	//
	virtual ~LibraryItem();

	string GetTitle() const
	{
		return _item->GetTitle();
	}

	double GetPrice() const
	{
		return _item->GetPrice();
	}

	string GetType() const { return _item->GetType(); };


private:
	// Это указатель на "обернутый объект"
	IItem* _item;

	//
	// Дополнительные (декорирующие) абстракции сущности, свойственные
	// единице хранения в библиотеке
	//

	// Инвентарный номер
	int _inventoryNumber;

	// Время владения книгой читателем
	int _holdPeriod;

	// Адрес объекта класса читатель, который владеет книгой в конкретный момент.
	// Если книга находится в библиотеке, то он должен быть NULL
	Reader* _reader;

};






LibraryItem::LibraryItem(IItem* item, int inventoryNumber)
	: _item(item),
	_inventoryNumber(inventoryNumber),
	_reader(NULL),
	_holdPeriod(0)

{

}

LibraryItem::~LibraryItem()
{

}


IItem* LibraryItem::GetItem()
{
	return _item;
}

#endif // !defined(AFX_LIBRARYITEM_H__A4915813_7738_4B67_82F1_17BA66EA451F__INCLUDED_)
