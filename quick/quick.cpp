#include "quick.h"
using namespace std; 


int main() 
{
	vector<int>data{23, 6, 4, -1, 0, 12, 8, 3, 1};
	QuickSorter<int>sorter;
	sorter.Sort(data);
	return 0;
}



