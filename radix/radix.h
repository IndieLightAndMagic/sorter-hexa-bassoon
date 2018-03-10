#ifndef __HEAP_H__
#define __HEAP_H__

#include <cmath>
#include <array>
#include <algorithm>
#include <sort/sort.h>

template <typename T>

class RadixSorter: public Sorter<T> {

	void RadixSort(std::vector<unsigned int>& u){

        std::array<std::vector<unsigned int>, 10> count;
        auto shift = 0;
        auto allzero = false;

        while (!allzero){
        	
        	allzero = true;
        	auto index = 0;
        	for (auto x:u){
        		
        		auto quotient = static_cast<int>(pow(10.0,shift));
        		count[(x/quotient)%10].push_back(x);
        		if (x/quotient) allzero = false;

        	}
        	shift++;

        	for (auto& v:count){
        		for (auto elem: v){
        			u[index++] = elem;
        		}
				v.clear();
        	}
        }
	}

public:

	RadixSorter(){}
	void Sort(std::vector<unsigned int>&u){
		RadixSort(u);
	}
};
#endif /*__HEAP_H__*/