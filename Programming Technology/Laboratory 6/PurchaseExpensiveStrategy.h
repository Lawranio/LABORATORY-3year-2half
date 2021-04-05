// PurchaseExpensiveStrategy.h: interface for the PurchaseExpensiveStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PURCHASEEXPENSIVESTRATEGY_H__81F20822_8C43_46B9_8927_B998ACDA7F28__INCLUDED_)
#define AFX_PURCHASEEXPENSIVESTRATEGY_H__81F20822_8C43_46B9_8927_B998ACDA7F28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IPurchaseStrategy.h"

//
// Реализация стратегии закупки печатного издания: закупать, если
// стоимость книги не ниже заданной.
//
class PurchaseExpensiveStrategy : public IPurchaseStrategy
{

public:
	bool IsAcceptable(const IItem& item);
	PurchaseExpensiveStrategy(int minPrice);
	virtual ~PurchaseExpensiveStrategy();


private:
	double _minPrice;

};





PurchaseExpensiveStrategy::PurchaseExpensiveStrategy(int minPrice)
	: _minPrice(minPrice)
{

}

PurchaseExpensiveStrategy::~PurchaseExpensiveStrategy()
{

}

bool PurchaseExpensiveStrategy::IsAcceptable(const IItem& item)
{
	bool result = true;
	if (item.GetPrice() < _minPrice)
	{
		result = false;
	}
	return result;
}

#endif // !defined(AFX_PURCHASEEXPENSIVESTRATEGY_H__81F20822_8C43_46B9_8927_B998ACDA7F28__INCLUDED_)
