#include <iostream>
#include <vector>
#include <sort/sort.h>
#include <insertion/insertion.h>

template <typename T>
class ShellSorter : public Sorter<T>
{
	unsigned long m_gaps;
	void TraverseAndCompare(std::vector<T>& u, long size, long pivot, unsigned long gapsize)
	{
		auto data = u.data();
		for (auto index0 = pivot + gapsize; index0 < size; index0 += gapsize)
		{
			for (auto index1 = index0; index1 > pivot && !this->IsSortedSequel(u, index1-gapsize, index1); index1 -= gapsize)
	        {
	        	std::swap(data[index1-1], data[index1]);
	        	 ++this->m_count;
	        }
		}
	}
public:
	ShellSorter(unsigned long gaps = 4):
	Sorter<T>(),
	m_gaps(gaps ? gaps : 4)
	{
	}

	void Sort(std::vector<T>& u) {
        this->ResetCounter();
        auto size = static_cast<long>(u.size());
        auto gapsize = size / m_gaps;
        while (gapsize>2){
	        for (auto pivot = 0; pivot < gapsize - 1; ++pivot)
			{
				this->Print(u);
				this->TraverseAndCompare(u, size, pivot, gapsize);
			} 
        	gapsize--;
        }
        InsertionSorter<T>sorter;
        sorter.Sort(u);
        this->m_count += sorter.GetCount();
		this->Print(u);
        std::cout << "** " << this->m_count << " **\n";
	}
};
