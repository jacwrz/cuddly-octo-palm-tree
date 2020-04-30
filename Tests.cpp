#include "Array_test.h"
//#include "Array_test_smart.h"
//uncomment one of the above for testing
#include <iostream>

void main()
{
	unsigned int size;
	std::cin >> size;
	Array<int> a(size);
	std::cout << "The size is: " << size <<std::endl;
	for (int i = 0; i != size; i++)
	{
		a.Set(i, i);
	}
	for (int i = 0; i != size; i++)
	{
		std::cout << a.Get(i) << " ";
	}

	std::cout << "\nCopy constructor b=a" << std::endl;
	Array<int> b = a;
	for (int i = 0; i != size; i++)
	{
		std::cout << b.Get(i) << " ";
	}

	std::cout << "\nSize 15" << std::endl;

	Array<int> c(15);
	for (int i = 0; i != 15; i++)
	{
		std::cout << c.Get(i) << " ";
	}

	c = b;
	std::cout << "\nAfter assignment c=b" << std::endl;

	for (int i = 0; i != 20; i++)
	{
		std::cout << c.Get(i) << " ";
	}

}
