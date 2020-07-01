#pragma once
#include "Counter.h"

class MyString
{
	Counter* m_pC;
public:
	MyString(const char* str)
	{
		m_pC = searchThisStr(str);
		if(!m_pC) m_pC = new Counter(str);
	}

	Counter* searchThisStr(const char* str)
	{
		Counter* p = Counter::Head;
		while (p != nullptr)//ищем эту строчку
		{
			if (!strcmp(p->m_pStr, str))
			{
				p->addOwner();           //нашли и стали пользоваться
				return p;
			}
			p = p->m_pNext;
		}
		return p;
	}

	~MyString()
	{
		if (Counter::Head) delete m_pC;
	}
};

