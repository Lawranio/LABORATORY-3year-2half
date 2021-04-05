// IPurchaseStrategy.h: interface for the IPurchaseStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IPURCHASESTRATEGY_H__463F6A66_FAFD_4D75_AACB_7D898CCFD535__INCLUDED_)
#define AFX_IPURCHASESTRATEGY_H__463F6A66_FAFD_4D75_AACB_7D898CCFD535__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IItem.h"

//
// Интерфейс для стратегии закупки печатного издания
//
class IPurchaseStrategy
{
public:

	// Возвращает true, если печатное издание подходит для закупки.
	// Здесь передается ссылка на объект (передача объекта
	// абстрактного класса по значению не может быть выполнена, т.к.
	// требует конструирования объекта)
	virtual bool IsAcceptable(const IItem& item) = 0;

};

#endif // !defined(AFX_IPURCHASESTRATEGY_H__463F6A66_FAFD_4D75_AACB_7D898CCFD535__INCLUDED_)
