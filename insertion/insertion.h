#ifndef __INSERTION_H__
#define __INSERTION_H__
#include <iostream>
#include <vector>
#include <sort/sort.h>

template <typename T>
class InsertionSorter : public Sorter<T>
{
	void TraverseAndCompare(std::vector<T>& u, long size, long pivot)
	{
		auto data = u.data();
		for (auto index = pivot; index > 0 && !this->IsSortedSequel(u,index-1,index); --index)
        {
        	std::swap(data[index-1], data[index]);
        	++this->m_count;
        }
	}
public:
	InsertionSorter():Sorter<T>(){
	}

	void Sort(std::vector<T>& u) override {
        this->ResetCounter();
        auto size = static_cast<long>(u.size());
        for (auto pivot = 1; pivot < size - 1; ++pivot)
		{
			this->Print(u);
			this->TraverseAndCompare(u, size, pivot);
		} 
		this->Print(u);
        std::cout << "** " << this->m_count << " **\n";
	}
};
#endif /* __INSERTION_H__ */