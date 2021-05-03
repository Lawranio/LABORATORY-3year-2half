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

	// ��� �������� ���������� ������ ���������� ���� �������
	// ��������� ������������ �������� ������� � ���������� 
	// ������� �������� �������� �������� ����������.
	Library(
		const string& name,
		IPurchaseStrategy* purchaseStrategy,
		IDeliveryStrategy* deliveryStrategy);

	// ��� ����������� �������, ���� ���������� � ������� 
	// ���������, � ������� ��������
	virtual ~Library();

	// �������� ����������
	string GetName()
	{
		return _name;
	}

	// ���������� ���������� �������� �������.
	// ���� ��� �����������, �� ������������ true,
	// � ��������� ������ - false
	bool PurchaseItem(IItem* item);

	// ���������������� ��������
	void AddReader(Reader* reader);

	// ������ ����� ��������
	void LetLibItemOut(LibraryItem* item, Reader* reader);

	// ������� ����� � ����������
	void PutLibItemBack(LibraryItem* libItem);

private:

	string _name;
	// ���������
	IPurchaseStrategy* _purchaseStrategy;
	IDeliveryStrategy* _deliveryStrategy;

	// ��������� ����������� ����������� �����
	int _lastInventoryNumber;

	// ��� ������ ��������
	vector<LibraryItem*> _libItems;

	// ��� ��������
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
	// ���������, �������� �� ���������� �������� �������
	// � ������������ � ��������� ������������
	if (_purchaseStrategy->IsAcceptable(*item))
	{
		// �������� ������� �������������, ��� ����������
		// �������� ��������. ������� ��������� ���������
		// ����������. ����������� ����������� �����
		_lastInventoryNumber++;
		LibraryItem* libItem = new LibraryItem(item, _lastInventoryNumber);

		_libItems.push_back(libItem);
		result = true;
	}
	else
	{
		// ������ �����������
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
	// �������� ����� ����� ������ ��������, �������������������
	// � ������ ����������
	if (find(_readers.begin(), _readers.end(), reader) != _readers.end())
	{
		// ����� ����� ������, ���� ��� �� ���� ����� ������  ��� ���� ���������
		if (item->GetReader() == NULL)
		{
			// �������� ����� ����� ������ �������
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
