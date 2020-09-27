#include "Counter.h"

size_t Counter::m_curCount = 0;
Counter* Counter::Head = 0;

Counter::Counter(const char* str) : m_nOwner(1)
{
	m_pStr = new char[strlen(str) + 1];
	strcpy_s(m_pStr, strlen(str) + 1, str);
	m_curCount++;
	m_pNext = Head;
	Head = this;
}

void Counter::removeOwner() 
{
	if (this) {
		m_nOwner--;
		if (m_nOwner < 1) {
			delete this;
		}
	}
}

Counter::~Counter() {

	if (this == Head)
	{
		Head = Head->m_pNext;
	}
	else {
		Counter* tmp = Head;
		while (tmp->m_pNext == this)
		{
			tmp = tmp->m_pNext;
		}
		tmp->m_pNext = this->m_pNext;
	}
	delete[] m_pStr;
	m_pStr = nullptr;
	m_curCount--;
	m_nOwner = 0;
}

Counter* Counter::searchThisStr(const char* str)
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

	return new Counter(str);
}

void Counter::printAll()
{
	Counter* p = Counter::Head;
	size_t count = 1;
	while (p != nullptr) {
		for (int i = 0; i < p->m_nOwner; i++) {
			std::cout << '\n' << count << ". " << p->m_pStr << '\n';
			count++;
		}
		p = p->m_pNext;
	}
}

void Counter::changeRegister()
{
	Counter* p = Counter::Head;
	while (p != nullptr) {
		for (int i = 0; i < strlen(p->m_pStr); i++) {
			if (isalpha(p->m_pStr[i])) { (p->m_pStr[i]) ^= 0x20; }
		}
		p = p->m_pNext;
	}
}