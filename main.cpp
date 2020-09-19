#include <iostream>
#include "MyString.h"
int main()
{
	{MyString Ar[] = { "ddd", "aaa", "aaa" };

	MyString::changeRegister();
	MyString::sort();
	MyString::printAll();
	}
	std::cout << "TEST";
	return 0;
}