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
// ��������� ��� ������� ��������. 
// ��������� ��������� � ��������� ����������� ��� �������������
// ������� ����������: ����������� �����, ������ �� ��������, 
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

	// ������ NULL, ���� ����� - � ����������
	Reader* GetReader()
	{
		return _reader;
	}

	// ���������� ��������� ������� ��������. ���� ����� �������, 
	// ������� �������� ��������� � ����������, �� ���� ����������
	// �������� NULL
	void SetReader(Reader* reader)
	{
		_reader = reader;
	}

	// ��� �������� ���������� ��������� �������, ����� �� 
	// ���� ��������� ��� ����������� �����.
	LibraryItem(IItem* item, int inventoryNumber);

	//
	// ��� ����������� ���������� ���� ���������� � "���������" ������
	// ����� �� ����� ��������� "�����" � ������
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
	// ��� ��������� �� "��������� ������"
	IItem* _item;

	//
	// �������������� (������������) ���������� ��������, ������������
	// ������� �������� � ����������
	//

	// ����������� �����
	int _inventoryNumber;

	// ����� �������� ������ ���������
	int _holdPeriod;

	// ����� ������� ������ ��������, ������� ������� ������ � ���������� ������.
	// ���� ����� ��������� � ����������, �� �� ������ ���� NULL
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
