#include <iostream>
#include "MyString.h"
int main()
{
	MyString Ar[4] = { "qqq","www","eee","www" };
	//Ar->printAll();
	
	MyString::changeRegister();
	MyString::printAll();
	return 0;
}