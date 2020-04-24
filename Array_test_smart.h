#include <iostream>
#include <memory>
#include <new>
template <class T>
class Array
{
private:
	std::unique_ptr<T[]> m_pData;
	unsigned int m_nSize;

	//Array(const Array&);
	//either copy constructor in priv or use of smart pointers
	//prevents double calling of destructor on same pointer

public:
	Array(unsigned int nSize) : m_nSize(nSize)
	{
		if (m_nSize > 0)
		{
			try
			{
				m_pData = std::make_unique<T[]>(nSize);
			}
			catch (std::bad_alloc& badAlloc)
			{
				m_nSize = 0;
				std::cerr << "bad_alloc caught, not enough memory: " << badAlloc.what() << std::endl;
			}
		}
	}

	bool Set(unsigned int nPos, const T& Value)
	{
		if (nPos < m_nSize && m_pData != nullptr) //both expressions necessary to be True to prevent memory access violation
		{
			m_pData[nPos] = Value;
			return true;
		}
		else
			return false;
	}

	T Get(unsigned int nPos)
	{
		if (nPos < m_nSize && m_pData != nullptr) //as in Setter
			return m_pData[nPos];
		else
			return T();
	}
};
//at least 4 bugs
//for at least 2:
//1. Provide a test case for each bug.
//2. Propose a fix for each bug.
//3. Find design problems assuming there are no bugs in Array class implementation.
//can't aggregate initialize it | lacks aggregate initialization (np. Arr [5] = {1, 2, 3, 4, 5})
//uninitialized variables
//delete should be delete[] |fixd
//what happens if Array<T> b(a)?
//