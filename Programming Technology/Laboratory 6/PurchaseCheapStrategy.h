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
// Реализация стратегии закупки печатного издания: закупать, если
// стоимость не превышает заданную.
//
class PurchaseCheapStrategy : public IPurchaseStrategy
{
public:

	// Реализация абстрактного метода из родтельского интерфейса.
	// Реализует проверку печатного издания на допустимую цену
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

	// Если цена более заданной максимальной,
	// то закупка не приемлема
	if (item.GetPrice() > _maxPrice)
	{
		result = false;
	}
	return result;
}

#endif // !defined(AFX_PURCHASECHEAPSTRATEGY_H__FC9FC695_FA47_4AD2_B23B_F5CF6DCD10A8__INCLUDED_)
