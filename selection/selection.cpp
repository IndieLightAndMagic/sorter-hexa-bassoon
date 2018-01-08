#include <iostream>
#include <vector>
#include <sort/sort.h>
using namespace std; 


template <typename T>
class SelectionSorter : public Sorter<T>
{
	void TraverseAndCompare(vector<T>& u, long size, long pivot)
	{
		auto data = u.data();
		for (auto index = pivot + 1; index < size ; ++index)
        {
        	if (data[index] < data[pivot])
        	{
        		//Some implementations exchange the indexes 
        		swap(data[index], data[pivot]);
        	}
        	this->m_count++;
        }
	}
public:
	SelectionSorter():Sorter<T>(){
	}

	void Sort(vector<T>& u) override {
        this->ResetCounter();
        auto size = static_cast<long>(u.size());
		for (auto pivot = 0; pivot < size - 1; ++pivot)
		{
			this->Print(u);
			this->TraverseAndCompare(u, size, pivot);
		} 
		this->Print(u);
        cout << "** " << this->m_count << " **\n";
	}
};




int main() 
{
	vector<int>data{100,56,10,5,4,2,1,1,-2,-3};
	SelectionSorter<int>sorter;
	sorter.Sort(data);
	return 0;
}



