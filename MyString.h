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

	MyString()
	{
		m_pC = nullptr;
	}

	Counter* searchThisStr(const char* str)
	{
		Counter* p = Counter::Head;
		while (p != nullptr)//���� ��� �������
		{
			if (!strcmp(p->m_pStr, str))
			{
				p->addOwner();           //����� � ����� ������������
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


	MyString(const MyString& other)
	{
		m_pC = other.m_pC;
		other.m_pC->addOwner();
	}

	MyString(MyString&& other)
	{

		m_pC = other.m_pC;
		other.m_pC = nullptr;
	}

	MyString& operator=(MyString&& other)
	{
		if (this == &other)
		{
			return *this;
		}
		m_pC->removeOwner();
		m_pC = other.m_pC;
		other.m_pC = nullptr;
		return *this;
	}
	//���� ������
	MyString& operator=(const MyString& other)
	{
		if (this == &other)
		{
			return *this;
		}
		m_pC->removeOwner();
		m_pC = other.m_pC;
		m_pC->addOwner();
		return *this;
	}
};

