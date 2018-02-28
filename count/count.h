#ifndef __HEAP_H__
#define __HEAP_H__

#include <array>
#include <algorithm>
#include <sort/sort.h>

template <typename T>

class CountSorter: public Sorter<int> {

	void CountSort(std::vector<int>& u){

        auto size = u.size();
        auto maxval = u[0];
        auto minval = u[0];

        for (int index = 0; index < size; ++index){
            if (u[index] >= maxval) maxval = u[index];
            else if (u[index] < minval) minval = u[index];
        }

        auto countsize = maxval - minval + 1;
        auto offset = minval;

        int* count = new int(countsize);
        memset(count, 0, sizeof(int)*countsize);
        for (int index = 0; index < size; ++index) count[u[index] - offset]++;

        auto indexu = 0; for (int index = 0; index < countsize; ++index){
            if (!count[index]) continue;
            while (count[index]--) u[indexu++] = index + offset;
        }
        free(count);
	}

public:

	CountSorter(){}
	void Sort(std::vector<int>&u){
		CountSort(u);
	}
};
#endif /*__HEAP_H__*/