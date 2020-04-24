#include <new>
#include <iostream>
template <class T>
class Array
{
private:
	T *m_pData;
	unsigned int m_nSize;
	Array(const Array&); //copy constructor in priv

public:
	Array(unsigned int nSize) : m_nSize(nSize), m_pData(NULL) //also initializing m_pData
	{
		if (m_nSize > 0)
		{
			m_pData = new (std::nothrow) T[m_nSize];
			if (m_pData == NULL)
			{ 
				std::cout << "Failed to allocate storage for Array\nSize given was: " << m_nSize << " or not an unsigned int\n";
				m_nSize = 0;
			}
		}
	}

	virtual ~Array()
	{
		delete[] m_pData; //null pointer check removed, operator changed to delete[]
	}

	bool Set(unsigned int nPos, const T& Value)
	{
		if (nPos < m_nSize && m_pData != NULL) //both expressions necessary to be True to prevent memory access violation
		{
			m_pData[nPos] = Value;
			return true;
		}
		else
		{
			return false;
		}
	}

	T Get(unsigned int nPos)
	{
		if (nPos < m_nSize && m_pData != NULL) //as in Setter
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