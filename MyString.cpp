#include "MyString.h"
#include <iostream>

void MyString::printAll()
{
	Counter* p = Counter::Head;
	size_t count = 1;
	while (p != nullptr)
	{
		std::cout<<'\n'<<count<<". "<<p->m_pStr<<'\n';
		count++;
		p = p->m_pNext;
	}
}

void MyString::changeRegister()
{
	Counter* p = Counter::Head;
	while (p != nullptr)
	{
		int len = strlen(p->m_pStr);
		for (int i = 0; i < len; i++)
		{
			(p->m_pStr[i]) ^= 0x20;
		}
		p = p->m_pNext;
	}
}