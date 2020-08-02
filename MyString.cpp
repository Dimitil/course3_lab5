#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <iostream>

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