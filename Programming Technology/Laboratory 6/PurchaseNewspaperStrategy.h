#ifndef PURCHASE_NEWSPAPER_STRATEGY_H
#define PURCHASE_NEWSPAPER_STRATEGY_H

#include "IPurchaseStrategy.h"

/*

	Реализация стратегии закупки печатного издания:
	закупать, если это газета

*/

class PurchaseNewspaperStrategy : public IPurchaseStrategy {

public:
	bool IsAcceptable(const IItem& item);
	PurchaseNewspaperStrategy() {};
	virtual ~PurchaseNewspaperStrategy() {};
};


bool PurchaseNewspaperStrategy::IsAcceptable(const IItem& item) {

	if (item.GetType() == "Газета") return true;
	else return false;
}
#endif // !PURCHASE_NEWSPAPER_STRATEGY_H
