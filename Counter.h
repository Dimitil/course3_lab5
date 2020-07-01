#pragma once
#include <cstring>

class Counter
{
	static Counter* Head;
	static size_t m_curCount;

	char* m_pStr;
	size_t m_nOwner;
	Counter* m_pNext;


	  Counter(const char* str)
	  {	  
		  //если не нашли такую строку то здесь нужно создать 
		  m_pStr = new char[strlen(str) + 1];
		  strcpy_s(m_pStr, strlen(str)+1, str);
		  m_curCount++;
		  addOwner(); 
		  if (!Head)
		  {
			  Head = this;
			  this->m_pNext = nullptr;
		  }
		  else
		  {
			  this->m_pNext = Head; //добавили в начало
			  Head = this;
		  }
		  
	  }
	  ~Counter()
	  {
		  if (!Head) return;

		  if (this == Head)
		  {
			  Head = this->m_pNext;
		  }
		  else
		  {
			  Counter* p = Head;
			  while (p->m_pNext != this)
			  {
				  p = p->m_pNext;
			  }
			  p->m_pNext = this->m_pNext;
			  this->m_pNext = nullptr;
		  }
			  delete[] m_pStr;
			  m_pStr = nullptr;
			  m_nOwner = NULL;
			  m_curCount--;
		  
	  }
	  void addOwner()
	  {
		  m_nOwner++;
	  }
	  void removeOwner()
	  {
		  m_nOwner--;
		  if (!m_nOwner)
		  {
			  m_curCount--;
			  delete this;
		  }
	  }	
	  friend class MyString;
};

