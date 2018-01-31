#ifndef __QUICK_H__
#define __QUICK_H__
#include <vector>
#include <sort/sort.h>

template <typename T>

class QuickSorter : public Sorter<T>
{
    unsigned int m_pivotalIndex = 0;

    void SortInplaceVector(std::vector<T>& unorderedVector, int from, int to, int pivotIndex = 0){
        
        auto begin = from;
        auto end = to;
        
        //Ordered by size definition.
        if (end - begin < 2)
        {
            if (unorderedVector[begin] > unorderedVector[end]) std::swap(unorderedVector[begin], unorderedVector[end]);
            this->Print(unorderedVector);
            return;
        }

        //Set up the partition
        this->Print(unorderedVector);
        std::swap(unorderedVector[end], unorderedVector[pivotIndex]);
        this->Print(unorderedVector);
        pivotIndex = end;
        end--;

        auto pivot = unorderedVector[pivotIndex];
        
        while (begin <= end){
            
            auto hi = unorderedVector[end];
            auto li = unorderedVector[begin];
            
            if (hi > pivot && li <= pivot){
                end--; begin++; continue;
            } else if ( hi > pivot ) {
                end--;
            } else if ( li <= pivot ) {
                begin++;
            } else {
                std::swap(unorderedVector[begin++], unorderedVector[end--]);
                this->Print(unorderedVector);
            }
        }
        
        if ( begin == pivotIndex) SortInplaceVector(unorderedVector, from, pivotIndex - 1, (from + pivotIndex - 1) >> 1);
        
        else if ( end == from - 1){
            
            this->Print(unorderedVector);
            std::swap(unorderedVector[from], unorderedVector[pivotIndex]);
            this->Print(unorderedVector);
            SortInplaceVector(unorderedVector, from + 1, pivotIndex, (from + 1 + pivotIndex) >> 1);
        
        } else {

            std::swap(begin, end);
            this->Print(unorderedVector);
            std::swap(unorderedVector[pivotIndex], unorderedVector[end]);
            this->Print(unorderedVector);

            SortInplaceVector(unorderedVector, from, begin, (from + begin) >> 1 );
            SortInplaceVector(unorderedVector, end + 1, pivotIndex, (end + 1 + pivotIndex) >> 1);

        }  

    }
    
public:
    QuickSorter():m_pivotalIndex(0){}
	void Sort(std::vector<T>& u)
	{
        auto sizeIndex = u.size()-1;
		SortInplaceVector(u, 0, sizeIndex, sizeIndex>>1);
	}

};

#endif /*__QUICK_H__*/
