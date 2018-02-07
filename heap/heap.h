#ifndef __HEAP_H__
#define __HEAP_H__

#include <vector>
#include <algorithm>
#include <sort/sort.h>

template <typename T>

class HeapSorter : public Sorter<T> {

	void MaxHeap(std::vector<T>& u, unsigned int index = 0, unsigned int unorderedsize = 0){
		
		auto leftIndex =  index * 2 + 1;
		auto rightIndex = index * 2 + 2;

		if (leftIndex < unorderedsize) MaxHeap(u, leftIndex);
		if (rightIndex < unorderedsize) MaxHeap(u, rightIndex);

		if (leftIndex < unorderedsize) {			
			if (rightIndex < unorderedsize) {
				if (u[rightIndex] > u[leftIndex]) std::swap(u[leftIndex], u[rightIndex]);
			}			
			if (u[leftIndex] > u[index]) std::swap(u[index], u[leftIndex]);  
		}

	}

	void SwapFirstLast(std::vector<T>& u, unsigned int unorderedsize){
		std::swap(u[0], u[unorderedsize - 1]);
	}

public:
	HeapSorter(){}
	void Sort(std::vector<T>&u){
		
		auto unorderedSizeIndex = u.size(); //The whole u is unordered.
		while(unorderedSizeIndex > 1){
		
			MaxHeap(u, 0, unorderedSizeIndex);
			SwapFirstLast(u, unorderedSizeIndex--);
		
		}
	}
};
#endif /*__HEAP_H__*/