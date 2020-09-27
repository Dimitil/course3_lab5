#pragma once
#include <cstring>
#include <iostream>

class Counter{
		static Counter* Head;
		static size_t m_curCount;
		char* m_pStr;
		size_t m_nOwner=0;
		Counter* m_pNext;

		Counter(const char* str);

		~Counter();

		void addOwner() { m_nOwner++; }

		void removeOwner();

		static Counter* searchThisStr(const char* str);
		
		static void printAll();

		static void changeRegister();

		friend class MyString;
}; 