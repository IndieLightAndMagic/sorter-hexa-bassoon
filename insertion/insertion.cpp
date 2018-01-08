#include <iostream>
#include <vector>
#include <sort/sort.h>
using namespace std; 


template <typename T>
class InsertionSorter : public Sorter<T>
{
	void TraverseAndCompare(vector<T>& u, long size, long pivot)
	{
		auto data = u.data();
		for (auto index = pivot; index > 0 && !this->IsSortedSequel(u,index-1,index); --index)
        {
        	swap(data[index-1], data[index]);
        	 ++this->m_count;
        }
	}
public:
	InsertionSorter():Sorter<T>(){
	}

	void Sort(vector<T>& u) override {
        this->ResetCounter();
        auto size = static_cast<long>(u.size());
        for (auto pivot = 1; pivot < size - 1; ++pivot)
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
	vector<int>data{55,-2,34,10,0,2,-5,12};
	InsertionSorter<int>sorter;
	sorter.Sort(data);
	return 0;
}



