#ifndef PURCHASE_NEWSPAPER_STRATEGY_H
#define PURCHASE_NEWSPAPER_STRATEGY_H

#include "IPurchaseStrategy.h"

/*

	���������� ��������� ������� ��������� �������:
	��������, ���� ��� ������

*/

class PurchaseNewspaperStrategy : public IPurchaseStrategy {

public:
	bool IsAcceptable(const IItem& item);
	PurchaseNewspaperStrategy() {};
	virtual ~PurchaseNewspaperStrategy() {};
};


bool PurchaseNewspaperStrategy::IsAcceptable(const IItem& item) {

	if (item.GetType() == "������") return true;
	else return false;
}
#endif // !PURCHASE_NEWSPAPER_STRATEGY_H
