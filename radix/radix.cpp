#include "radix.h"
using namespace std;

int main(){
	vector<unsigned int>data{34, 3, 0, 2, 14, 8, 1, 24};
	RadixSorter<unsigned int>sorter;
	sorter.Sort(data);
	sorter.Print(data);
	return 0;
}