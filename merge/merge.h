#ifndef __MERGE_H__
#define __MERGE_H__
#include <iostream>
#include <vector>
#include <sort/sort.h>

template <typename T>

class MergeSorter : public Sorter<T>
{
    unsigned int m_pivotalIndex = 0;
    void PrintPartitions(const std::vector<T>& u, unsigned int pivotIndex, unsigned int depth = 0) {

        while (depth--) std::cout << "    ";
        auto uSize = u.size();
        for(auto index = 0; index < uSize ; ++index) std::cout << (index == pivotIndex ? " [" : " ") << u[index] << (index == pivotIndex ? "] " : "");
        std::cout << "\n";
        
    }

    void MergePartitions(std::vector<T>& u, unsigned int startIndex, unsigned int pivotIndex, unsigned int endIndex) {

        auto indexLeft = startIndex;
        auto indexRight = pivotIndex + 1;
        
        std::vector<T> temp;
        while (indexLeft <= pivotIndex && indexRight <= endIndex) {
            
            if (u[indexLeft] <= u[indexRight]) temp.push_back(u[indexLeft++]);
            else temp.push_back(u[indexRight++]);
            
            if (indexLeft > pivotIndex) while (indexRight <= endIndex) temp.push_back(u[indexRight++]);
            else if (indexRight > endIndex) while (indexLeft <= pivotIndex) temp.push_back(u[indexLeft++]);            
        }
        
        auto tempSz = temp.size();
        for (unsigned int index = 0; index < tempSz; ++index) u[startIndex + index] = temp[index];

    }

    void Partitionate(std::vector<T>& u, unsigned int startIndex, unsigned int endIndex, unsigned int depth = 0) {
        this->Print(u,startIndex, endIndex);
        if (endIndex - startIndex == 1)
        {
            if (u[startIndex] > u[endIndex]) std::swap(u[startIndex], u[endIndex]);
            return;
        }
        unsigned int pivotIndex = startIndex + endIndex;
        pivotIndex >>= 1;

        Partitionate(u, startIndex, pivotIndex, depth + 1);
		Partitionate(u, pivotIndex + 1, endIndex, depth + 1);
        
        this->PrintPartitions(u, pivotIndex, depth);
        MergePartitions(u, startIndex, pivotIndex, endIndex);
        
        
	
    }
public:
    MergeSorter():m_pivotalIndex(0){}
	void Sort(std::vector<T>& u)
	{
		Partitionate(u, 0, u.size() - 1);
	}
    void setPivotalIndex(unsigned int pivotalIndex)
    {
        m_pivotalIndex = pivotalIndex;
    }

};

#endif /*__MERGE_H__*/
