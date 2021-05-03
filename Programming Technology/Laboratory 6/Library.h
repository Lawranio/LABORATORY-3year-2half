// Library.h: interface for the Library class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIBRARY_H__24F4459E_E564_44D8_B05D_8D49D29181BD__INCLUDED_)
#define AFX_LIBRARY_H__24F4459E_E564_44D8_B05D_8D49D29181BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IPurchaseStrategy.h"
#include "IDeliveryStrategy.h"
#include "IItem.h"
#include "LibraryItem.h"
#include <vector>
#include <algorithm>

class Library
{
public:
	vector<LibraryItem*> GetLibItems();
	vector<Reader*>& GetReaders();

	// При создании экземпляра класса библиотека надо указать
	// стратегии приобретения печатных изданий и вычисления 
	// периода владения единицей хранения читателями.
	Library(
		const string& name,
		IPurchaseStrategy* purchaseStrategy,
		IDeliveryStrategy* deliveryStrategy);

	// При уничтожении объекта, надо уничтожить и объекты 
	// стратегий, и единицы хранения
	virtual ~Library();

	// Название библиотеки
	string GetName()
	{
		return _name;
	}

	// Попытаться приобрести печатное издание.
	// Если оно приобретено, то возвращается true,
	// в противном случае - false
	bool PurchaseItem(IItem* item);

	// Зарегистрировать читателя
	void AddReader(Reader* reader);

	// Выдать книгу читателю
	void LetLibItemOut(LibraryItem* item, Reader* reader);

	// Вернуть книгу в библиотеку
	void PutLibItemBack(LibraryItem* libItem);

private:

	string _name;
	// Стратегии
	IPurchaseStrategy* _purchaseStrategy;
	IDeliveryStrategy* _deliveryStrategy;

	// Последний присвоенный инвентарный номер
	int _lastInventoryNumber;

	// Все единцы хранения
	vector<LibraryItem*> _libItems;

	// Все читатели
	vector<Reader*> _readers;
};






Library::Library(
	const string& name,
	IPurchaseStrategy* purchaseStrategy,
	IDeliveryStrategy* deliveryStrategy)
	: _name(name),
	_purchaseStrategy(purchaseStrategy),
	_deliveryStrategy(deliveryStrategy),
	_lastInventoryNumber(0)
{

}

Library::~Library()
{
	if (_purchaseStrategy != NULL)
	{
		delete _purchaseStrategy;
	}

	if (_deliveryStrategy != NULL)
	{
		delete _deliveryStrategy;
	}

	for (int i = 0; i < _libItems.size(); i++)
	{
		delete _libItems[i];
	}
}

bool Library::PurchaseItem(IItem* item)
{
	bool result;
	// Проверить, возможно ли приобрести печатное издание
	// в соответствии с политикой приобретения
	if (_purchaseStrategy->IsAcceptable(*item))
	{
		// Печатное издание приобретается, оно становится
		// единицей хранения. Поэтому создается экземпляр
		// декоратора. Назначается инвентарный номер
		_lastInventoryNumber++;
		LibraryItem* libItem = new LibraryItem(item, _lastInventoryNumber);

		_libItems.push_back(libItem);
		result = true;
	}
	else
	{
		// Нельзя приобретать
		result = false;
	}
	return result;
}

void Library::AddReader(Reader* reader)
{
	_readers.push_back(reader);
}

void Library::LetLibItemOut(LibraryItem* item, Reader* reader)
{
	// Выдавать книгу можно только читателю, зарегистрированному
	// в данной библиотеке
	if (find(_readers.begin(), _readers.end(), reader) != _readers.end())
	{
		// Книгу можно выдать, если она не была взята другим  или этим читателем
		if (item->GetReader() == NULL)
		{
			// Получить книгу может только инженер
			int holdPeriod = _deliveryStrategy->HoldPeriod(*reader);

			item->SetHolderPeriod(holdPeriod);
			item->SetReader(reader);
		}
	}
}

void Library::PutLibItemBack(LibraryItem* libItem)
{
	libItem->SetReader(NULL);
}

vector<Reader*>& Library::GetReaders()
{
	return _readers;
}

vector<LibraryItem*> Library::GetLibItems()
{
	return _libItems;
}

#endif // !defined(AFX_LIBRARY_H__24F4459E_E564_44D8_B05D_8D49D29181BD__INCLUDED_)
