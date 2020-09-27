#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <iostream>

MyString::MyString()
{
	m_pC = nullptr; 
}

MyString::~MyString()
{
	if (m_pC)
	{
		m_pC->removeOwner();	//исправлено
	}
	m_pC = nullptr;
}

MyString::MyString(const char* str)
{
	m_pC = searchThisStr(str);			//исправлено
}

Counter* MyString::searchThisStr(const char* str)
{													//исправлено 
	return Counter::searchThisStr(str);
}

MyString::MyString(const MyString& other)
{
	m_pC = other.m_pC;
	other.m_pC->addOwner();
}

MyString::MyString(MyString&& other) noexcept
{
	m_pC = other.m_pC;
	other.m_pC = nullptr;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this == &other) {
		return *this;
	}
	m_pC->removeOwner();			//исправлено
	m_pC = other.m_pC;
	other.m_pC = nullptr;
	return *this;
}

MyString& MyString::operator=(const MyString& other)
{
	if (this == &other) {
		return *this;
	}
	m_pC->removeOwner();
	m_pC = other.m_pC;
	m_pC->addOwner();
	return *this;
}

void MyString::printAll() {
	Counter::printAll(); //исправлено
}

void MyString::changeRegister()
{
	Counter::changeRegister();
}

void MyString::sort() {
    Counter* a, * b, * p, * h = NULL;

    for (Counter* i = Counter::Head; i != NULL; ) {
        a = i;
        i = i->m_pNext;
        b = h;
        for (p = NULL; (b != NULL) && (strcmp(a->m_pStr, b->m_pStr)>0); ) {
            p = b;
            b = b->m_pNext;
        }
        if (p == NULL) {
            a->m_pNext = h;
            h = a;
        }
        else {
            a->m_pNext = b;
            p->m_pNext = a;
        }
    }
    if (h != NULL)
        Counter::Head = h;
}