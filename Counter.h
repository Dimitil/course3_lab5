#pragma once
#include <cstring>
#include <iostream>

class Counter{
		static Counter* Head;
		static size_t m_curCount;
		char* m_pStr;
		size_t m_nOwner;
		Counter* m_pNext;

		Counter() {
			m_pStr = new char('\0');
			m_curCount++;
			addOwner();
			if (!Head) {
				this->m_pNext = nullptr;
			}
			else {
				this->m_pNext = Head; //добавили в начало
			}
			Head = this;
		}
		Counter(const char* str){	  //если не нашли такую строку то здесь нужно создать 
		  m_pStr = new char[strlen(str) + 1];
		  strcpy_s(m_pStr, strlen(str)+1, str);
		  m_curCount++;
		  addOwner(); 
		  if (!Head) {
			  this->m_pNext = nullptr;
		  }
		  else {
			  this->m_pNext = Head; //добавили в начало
		  }
		  Head = this;
		}
		~Counter() {
			if (m_curCount == 1) {//последний. он же head
				delete[] m_pStr;
				m_pStr = nullptr;
				Head = nullptr;
				m_curCount=0;
				return;
			}

			if (this == Head) {//попали на начало.
				Head = this->m_pNext; //теперь начало - следующий			  
			}
			else {             //попали не на начало и не на голову (в середине где-то)
				Counter* p = Head;
				while (p->m_pNext != this)  {
					p = p->m_pNext;
				}
				p->m_pNext = m_pNext;
			}
			m_pNext = nullptr;
			delete[] m_pStr;
			m_pStr = nullptr;
			m_curCount--;
			m_nOwner = 0;
		}

		void addOwner() { m_nOwner++; }

		void removeOwner() {
			if (this) {
				m_nOwner--;
				if (m_nOwner<1) {
				  delete this;
				}
			}
		}	

		friend class MyString;
};

