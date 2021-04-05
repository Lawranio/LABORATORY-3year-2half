// PurchaseCheapStrategy.h: interface for the PurchaseCheapStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PURCHASECHEAPSTRATEGY_H__FC9FC695_FA47_4AD2_B23B_F5CF6DCD10A8__INCLUDED_)
#define AFX_PURCHASECHEAPSTRATEGY_H__FC9FC695_FA47_4AD2_B23B_F5CF6DCD10A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IPurchaseStrategy.h"

//
// ���������� ��������� ������� ��������� �������: ��������, ����
// ��������� �� ��������� ��������.
//
class PurchaseCheapStrategy : public IPurchaseStrategy
{
public:

	// ���������� ������������ ������ �� ������������ ����������.
	// ��������� �������� ��������� ������� �� ���������� ����
	bool IsAcceptable(const IItem& item);

	PurchaseCheapStrategy(double maxPrice);
	virtual ~PurchaseCheapStrategy();

private:
	double _maxPrice;

};





PurchaseCheapStrategy::PurchaseCheapStrategy(double maxPrice) : _maxPrice(maxPrice)
{

}

PurchaseCheapStrategy::~PurchaseCheapStrategy()
{

}

bool PurchaseCheapStrategy::IsAcceptable(const IItem& item)
{
	bool result = true;

	// ���� ���� ����� �������� ������������,
	// �� ������� �� ���������
	if (item.GetPrice() > _maxPrice)
	{
		result = false;
	}
	return result;
}

#endif // !defined(AFX_PURCHASECHEAPSTRATEGY_H__FC9FC695_FA47_4AD2_B23B_F5CF6DCD10A8__INCLUDED_)
