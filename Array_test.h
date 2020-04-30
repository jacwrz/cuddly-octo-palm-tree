#include <new>
#include <iostream>
template <class T>
class Array
{
private:
	T *m_pData;
	unsigned int m_nSize;

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

	Array(const Array& source_array) : m_pData(NULL)
	{
		//deep copy constructor for class template
		//even that Array is a template, it's referred to inside
		//the class, like in the function signatures
		//and is treated as the full type Array<T>
		m_nSize = source_array.m_nSize;
		if (m_nSize > 0)
		{
			try
			{
				m_pData = new (std::nothrow) T[m_nSize];
				copy(source_array);
			}
			catch (std::bad_alloc& badAlloc)
			{
				m_nSize = 0;
				std::cerr << "bad_alloc caught in copy constructor, not enough memory: " << badAlloc.what() << std::endl;
			}
		}
	}

	void copy(const Array& source_array)
	{
		// Copies size of array and its values
		// going in reverse for easier stop-point
		T *p = m_pData + m_nSize;
		T *q = source_array.m_pData + m_nSize;
		while (p > m_pData)
			*--p = *--q;
	}

	Array& operator=(const Array& source_array)
	{
		//Copy assignment operator for class template
		//size stays as it was, to prevent heap corruption
		T* p = m_pData + m_nSize;
		T* q = source_array.m_pData + m_nSize;
		while (p > m_pData)
			*--p = *--q;
		return *this;
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