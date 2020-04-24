//#include "Array_test.h"
#include "Array_test_smart.h"
//uncomment one of the above for testing
#include <iostream>

int main()
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

	Array<int> b(5);
	//Array<int> c = b; //makes the build fail
}
