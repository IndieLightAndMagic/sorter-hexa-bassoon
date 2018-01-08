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
	static bool IsSortedSequel(const vector<T>&u, long index0, long index1)
	{
		return u[index0] <= u[index1];
	}
};

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



