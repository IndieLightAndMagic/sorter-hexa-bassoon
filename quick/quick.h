#ifndef __QUICK_H__
#define __QUICK_H__
#include <vector>
#include <sort/sort.h>

template <typename T>

class QuickSorter : public Sorter<T>
{
    unsigned int m_pivotalIndex = 0;

    void SortInplaceVector(std::vector<T>& unorderedVector, int from, int to){
        
        //Ordered by size definition.
        if (to - from < 2)
        {
            if (unorderedVector[from] > unorderedVector[to]) std::swap(unorderedVector[from], unorderedVector[to]);
            this -> Print(unorderedVector);
            return;
        }
        
        auto pivotIndex = from + to;
        pivotIndex >>= 1;
        
        auto pivot = unorderedVector[pivotIndex];
        
        //Set up the partition
        std::swap(unorderedVector[pivotIndex], unorderedVector[to]);
        this -> Print(unorderedVector);
        pivotIndex = from;
        for (auto index = from; index < to; ++index){
            
            if(unorderedVector[index] <= pivot) {
                std::swap(unorderedVector[index], unorderedVector[pivotIndex++]);
                this -> Print(unorderedVector);
            }            
        }
        std::swap(unorderedVector[pivotIndex], unorderedVector[to]);
        this -> Print(unorderedVector);

        //Swap Partitions
        SortInplaceVector(unorderedVector, from, pivotIndex - 1);
        SortInplaceVector(unorderedVector, pivotIndex + 1, to);
                   
    }
    
public:
    QuickSorter():m_pivotalIndex(0){}
	void Sort(std::vector<T>& u)
	{
        auto sizeIndex = u.size()-1;
		SortInplaceVector(u, 0, sizeIndex);
	}

};

#endif /*__QUICK_H__*/
