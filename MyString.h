#pragma once
#include "Counter.h"

class MyString
{
	Counter* m_pC;

	Counter* searchThisStr(const char* str);
		

public:
	MyString(const char* str);

	MyString();

	~MyString();

	MyString(const MyString& other);

	MyString(MyString&& other) noexcept;

	MyString& operator=(MyString&& other) noexcept;
	
	MyString& operator=(const MyString& other);

	static void printAll();

	static void changeRegister();

	static void sort();
};