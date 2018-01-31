#ifndef __MERGE_H__
#define __MERGE_H__
#include <vector>
#include <sort/sort.h>

template <typename T>

class MergeSorter : public Sorter<T>
{
    unsigned int m_pivotalIndex = 0;
    void CompilePartitions(std::vector<T>& unorderedVector, std::vector<T>& lowerPartitionVector, std::vector<T>& higherPartitionVector){
    
        auto usize = unorderedVector.size();
        auto pivotalValue = unorderedVector[m_pivotalIndex];
        auto equalCount = 0;
        
        for(auto index = 0; index < usize; ++index){
            if (index == m_pivotalIndex) continue;
            if (unorderedVector[index] > pivotalValue){ higherPartitionVector.push_back(std::forward<T>(unorderedVector[index])); continue; }
            if (unorderedVector[index] < pivotalValue){ lowerPartitionVector.push_back(std::forward<T>(unorderedVector[index])); continue; }
            if (unorderedVector[index] == pivotalValue){ equalCount++; }
        }
        
        unorderedVector.clear();
        unorderedVector.push_back(pivotalValue);
        while(equalCount--){ unorderedVector.push_back(pivotalValue); }
    
    }
    void PrintPartitions(const std::vector<T>& lower, const std::vector<T>& pivot, const std::vector<T>& higher, unsigned int depth = 0) {

        while (depth--) std::cout << "    ";
        for(auto e: lower) std::cout << " " << e;
        std::cout << " -+- ";
        for(auto e: pivot) std::cout << " " << e;
        std::cout << " -+- ";
        for(auto e: higher) std::cout << " " << e;
        std::cout << "\n";
        
    }
    void MergePartitions(std::vector<T>& unorderedVector, std::vector<T>& lowerPartitionVector, std::vector<T>& higherPartitionVector) {
        
        auto it = unorderedVector.begin();
        for(auto e: lowerPartitionVector) { unorderedVector.insert(it,e); ++it; }
        for (auto e: higherPartitionVector) unorderedVector.push_back(e);
        
    }
    void Partitionate(std::vector<T>& u, unsigned int depth = 0)
	{
		if (this->IsSorted(u)) return;

		std::vector<T> lowerPartition;
		std::vector<T> higherPartition;
        
        CompilePartitions(u, lowerPartition, higherPartition);
        this->PrintPartitions(lowerPartition, u, higherPartition, depth);
		
        Partitionate(lowerPartition, depth + 1);
		Partitionate(higherPartition, depth + 1);
        this->PrintPartitions(lowerPartition, u, higherPartition, depth);
        
        MergePartitions(u, lowerPartition, higherPartition);
		
        for (auto index = 0; index < depth; ++index) std::cout << "    "; std::cout << "U : "; this->Print(u);
        
	}
public:
    MergeSorter():m_pivotalIndex(0){}
	void Sort(std::vector<T>& u)
	{
        
		Partitionate(u);
	}
    void setPivotalIndex(unsigned int pivotalIndex)
    {
        m_pivotalIndex = pivotalIndex;
    }

};

#endif /*__MERGE_H__*/