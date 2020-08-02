#include <iostream>
#include "MyString.h"
int main()
{
	MyString Ar[6] = {"ddd", "DDD", "111", "aaa", "qqq", "aaa"};
	
	MyString::changeRegister();
	MyString::sort();
	MyString::printAll();
	return 0;
}