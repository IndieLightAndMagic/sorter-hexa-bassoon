#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <memory>

using namespace std;

struct Header {
	const char *pFilename;
	std::size_t elemsPerArray, nArrays, elemSize;
	long minlimit, maxlimit, span;
};
constexpr size_t totalElements(const Header& rHeader) { return rHeader.elemsPerArray * rHeader.nArrays; }

std::size_t Save(const Header& rHeader, unsigned char* pData) {

	auto pf = fopen(rHeader.pFilename, "wb");
	if (!pf) return 0;

	//Save Header
	auto fwriteCount = fwrite(&rHeader, sizeof(Header), 1, pf);
	
	// Calc Name Size, Save Size+1, Save Filename
	auto filenameSz = strlen(rHeader.pFilename)+1;
	fwriteCount += fwrite(&filenameSz, sizeof(filenameSz), 1, pf);
	fwriteCount += fwrite(rHeader.pFilename, filenameSz+1, 1, pf);

	// Save Data 
	fwriteCount += fwrite(pData, rHeader.elemSize, totalElements(rHeader), pf); 

	// Close File Stream
	fclose(pf);

	// Return bytes written
	return fwriteCount;

}

#ifdef _GENERATE_
int main(int argc, const char ** argv)
{
	Header h;	
	h.pFilename = argc>1 ?  argv[1] : "data.out";
	h.elemsPerArray = argc>2 ? atol(argv[2]) : 100;
	h.nArrays  = argc>3 ? atol(argv[3]) : 1000;
	h.minlimit = argc>4 ? atol(argv[4]) : -255;
	h.maxlimit = argc>5 ? atol(argv[5]) : 255;
	h.span = h.maxlimit - h.minlimit + 1;
	



	srand(time(0));
	auto v = make_unique<long[]>(totalElements(h));
	
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
