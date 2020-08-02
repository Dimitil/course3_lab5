#pragma once
#include "Counter.h"

class MyString
{
		Counter* m_pC;

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

	public:
		MyString(const char* str) {
			m_pC = searchThisStr(str);
			if(!m_pC) m_pC = new Counter(str);
		}

		MyString()	{
			m_pC = searchThisStr("");
			if (!m_pC) m_pC = new Counter();
		}

		~MyString()	{
			m_pC->removeOwner();
			m_pC = nullptr;
		}

		MyString(const MyString& other)	{
			m_pC = other.m_pC;
			other.m_pC->addOwner();
		}

		MyString(MyString&& other)	{
			m_pC = other.m_pC;
			other.m_pC = nullptr;
		}

		MyString& operator=(MyString&& other){
			if (this == &other)	{
				return *this;
			}
			m_pC->removeOwner();
			m_pC = other.m_pC;
			other.m_pC = nullptr;
			return *this;
		}
	
		MyString& operator=(const MyString& other)	{
			if (this == &other)	{
				return *this;
			}
			m_pC->removeOwner();
			m_pC = other.m_pC;
			m_pC->addOwner();
			return *this;
		}

		static void printAll();
		static void changeRegister();
		static void sort();
};