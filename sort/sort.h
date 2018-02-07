#ifndef __SORT_H__
#define __SORT_H__
#include <iostream>
#include <vector>

template <typename T>
class Sorter
{
protected:
    unsigned long m_count;
public:
	Sorter(){}
    void ResetCounter(){ m_count = 0; }
	virtual void Sort(std::vector<T>&u) = 0;
	virtual bool IsSorted(const std::vector<T>&u){
		if (u.size()<=1) return true;
		for (auto it = u.begin(); it != u.end(); ++it)
	
		{
			if (it + 1 == u.end()) continue;
			if (*it > *(it+1)){
				return false;
			}
		}
		return true;

	}
	virtual void Print(std::vector<T>u, int startIndex = 0, int endIndex = -1)
	{
        endIndex = (endIndex == -1) ? u.size() - 1 : endIndex;
        for (int index = startIndex; index <= endIndex; ++index )
		{
			std::cout << u[index] << (index + 1 == u.size() ? "\n" : " .. ");
		}
        std::cout << "\n";
	}
	static bool IsSortedSequel(const std::vector<T>&u, long index0, long index1)
	{
		return u[index0] <= u[index1];
	}
	unsigned long GetCount()
	{
		return this->m_count;
	}
};
#endif /*__SORT_H__*/
