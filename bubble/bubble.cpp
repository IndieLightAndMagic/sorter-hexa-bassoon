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



