#include <iostream>
#include <vector>

using namespace std; 

template <typename T>
class Sorter
{
protected:
    unsigned long m_count;
public:
	Sorter(){}
    void ResetCounter(){ m_count = 0; }
	virtual void Sort(vector<T>&u) = 0;
	virtual bool IsSorted(vector<T>u){
		for (auto it = u.begin(); it != u.end(); ++it)
		{
			if (it + 1 == u.end()) continue;
			if (*it > *(it+1)){
				return false;
			}
		}
		return true;
	}
	virtual void Print(vector<T>u)
	{	
		for (auto it = u.begin(); it != u.end(); ++it)
		{
			cout << *it << (it + 1 == u.end() ? "\n" : " .. ");
		}
	}
};

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



