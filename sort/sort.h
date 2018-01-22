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
	virtual void Print(std::vector<T>u)
	{	
		for (auto it = u.begin(); it != u.end(); ++it)
		{
			std::cout << *it << (it + 1 == u.end() ? "\n" : " .. ");
		}
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