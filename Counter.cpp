#include "Counter.h"

size_t Counter::m_curCount = 0;
Counter* Counter::Head = 0;

Counter::Counter(const char* str) 
{
	m_pStr = new char[strlen(str) + 1];
	strcpy_s(m_pStr, strlen(str) + 1, str);
	m_curCount++;
	addOwner();
	if (!Head) {
		m_pNext = nullptr;
	}
	else {
		m_pNext = Head;
	}
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
		while (tmp != nullptr)
		{
			if (tmp->m_pNext == this)
			{
				tmp->m_pNext = this->m_pNext;
				break;
			}
			tmp = tmp->m_pNext;
		}
	}
	delete[] m_pStr;
	m_pStr = nullptr;
	m_curCount--;
	m_nOwner = 0;
	m_curCount--;
}