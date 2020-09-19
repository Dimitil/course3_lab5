#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <iostream>

MyString::MyString()
{
	m_pC = searchThisStr("");
	if (!m_pC) m_pC = new Counter("");
}

MyString::~MyString()
{
	m_pC->removeOwner();
	m_pC = nullptr;
}

MyString::MyString(const char* str)
{
	m_pC = searchThisStr(str);
	if (!m_pC) m_pC = new Counter(str);
}

Counter* MyString::searchThisStr(const char* str)
{
	Counter* p = Counter::Head;
	while (p != nullptr)
	{
		if (!strcmp(p->m_pStr, str))
		{
			p->addOwner();           
			return p;
		}
		p = p->m_pNext;
	}
	return p;
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
	Counter* p = Counter::Head;
	size_t count = 1;
	while (p != nullptr){
		for (int i = 0; i < p->m_nOwner; i++) {
			std::cout << '\n' << count << ". " << p->m_pStr << '\n';
			count++;
		}
		p = p->m_pNext;
	}
}

void MyString::changeRegister()
{
	Counter* p = Counter::Head;
	while (p != nullptr) {
		for (int i = 0; i < strlen(p->m_pStr); i++)	{
			if (isalpha(p->m_pStr[i])) { (p->m_pStr[i]) ^= 0x20; }
		}
		p = p->m_pNext;
	}
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