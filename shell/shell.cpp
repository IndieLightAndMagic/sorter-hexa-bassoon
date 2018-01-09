#include "shell.h"
using namespace std; 


int main() 
{
	vector<int>data{34, -3, 0, 2, 14, 8, -1, 24};
	ShellSorter<int>sorter;
	sorter.Sort(data);
	return 0;
}



