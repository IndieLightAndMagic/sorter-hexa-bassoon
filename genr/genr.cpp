#include <cstdio>
#include <string>
#include <ctime>
#include <memory>

using namespace std;
int main(int argc, const char ** argv)
{	
	auto filename = argc>1 ?  argv[1] : "data.out";

	long sz = argc>2 ? atol(argv[2]) : 100;
	long n  = argc>3 ? atol(argv[3]) : 1000;
	auto minlimit = argc>4 ? atol(argv[4]) : -255;
	auto maxlimit = argc>5 ? atol(argv[5]) : 255;
	auto span = maxlimit - minlimit + 1;
	auto totalsz = n*sz;
	srand(time(0));
	auto v = make_unique<long[]>(totalsz);
	for (auto index = 0; index < totalsz; ++index)
	{
		auto randv = (rand() % span);
		auto limitv = minlimit + randv;
		v[index] = static_cast<long>(limitv);
	}

	auto fp = fopen(filename, "wb"); //b to disable \n in windows.
	if (fp)
	{
		auto vadd = v.get();
		fwrite(&sz,	sizeof(long),	1,			fp);
		fwrite(&n,	sizeof(long),	1,			fp);
		fwrite(vadd,sizeof(long), 	totalsz,	fp);

	}
	fclose(fp);
}
