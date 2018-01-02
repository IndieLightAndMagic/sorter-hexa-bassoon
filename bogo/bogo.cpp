#include <cstdlib>
#include <iostream>
#include <ctime>
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
	virtual void Sort(vector<T>u) = 0;
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
			cout << *it << (it + 1 == u.end() ? "\n" : " -- ");
		}
	}
};

template <typename T>
class Bogosorter : public Sorter<T>
{
	void Shuffle(vector<T>& u)
	{
		auto data = u.data();
		auto size = static_cast<long> (u.size());
        
        auto r = static_cast<double>(rand());
        auto rindex = r/RAND_MAX;
        auto index1 = static_cast<long>     (rindex * size);
        
        long index0;
        do{
            r = static_cast<double>(rand());
            rindex = r/RAND_MAX;
            index0 = static_cast<long>     (rindex * size);
        }while(index0 == index1 || data[index0] == data[index1]);
        
        
        std::swap(data[index0], data[index1]);
        
	}
public:
	Bogosorter():Sorter<T>(){
		srand(time(0)); // use current time as seed for random generator
	}

	void Sort(vector<T>u) override {
        this->ResetCounter();
        do{
            this->Print(u);
			this->Shuffle(u);
            this->m_count++;
		}while(!this->IsSorted(u));
        this->Print(u);
        cout << "** " << this->m_count << " **\n";
	}
};




int main() 
{
	vector<int>data{1,100,56,-3,1,2,5,4,-2,10};
	Bogosorter<int>sorter;
	sorter.Sort(data);
	return 0;
}



