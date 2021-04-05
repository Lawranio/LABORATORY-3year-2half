// IDeliveryStrategy.h: interface for the IDeliveryStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IDELIVERYSTRATEGY_H__E4A46F74_2FDF_4E05_B05B_A0ED226E11DE__INCLUDED_)
#define AFX_IDELIVERYSTRATEGY_H__E4A46F74_2FDF_4E05_B05B_A0ED226E11DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Reader.h"

//
// Интерфейс стратегии определения времени владения книгой
//
class IDeliveryStrategy
{
public:

	// Вычислить период (в днях) владения книгой для заданного читателя
	virtual int HoldPeriod(const Reader& reader) const = 0;

};
#endif // !defined(AFX_IDELIVERYSTRATEGY_H__E4A46F74_2FDF_4E05_B05B_A0ED226E11DE__INCLUDED_)
