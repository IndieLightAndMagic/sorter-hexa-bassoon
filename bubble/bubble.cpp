#include <iostream>
#include <vector>
#include <sort/sort.h>
using namespace std; 

template <typename T>
class BubbleSorter : public Sorter<T>
{
	void TraverseAndCompare(vector<T>& u, long size, long pivot)
	{
		auto data = u.data();
		auto top = size - (pivot + 1);	
        for (auto index = 0; index < top ; ++index)
        {
        	if (data[index] > data[index + 1])
        	{
        		swap(data[index], data[index + 1]);
        	}
        	this->m_count++;
        }
	}
public:
	BubbleSorter():Sorter<T>(){
	}

	void Sort(vector<T>& u) override {
        this->ResetCounter();
        auto size = static_cast<long>(u.size());
		for (auto pivot = 0; pivot < size; ++pivot)
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
	BubbleSorter<int>sorter;
	sorter.Sort(data);
	return 0;
}



