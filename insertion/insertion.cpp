#include "insertion.h" 





using namespace std;
int main() 
{
	vector<int>data{55,-2,34,10,0,2,-5,12};
	InsertionSorter<int>sorter;
	sorter.Sort(data);
	return 0;
}



