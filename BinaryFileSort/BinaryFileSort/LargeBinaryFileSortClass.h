#pragma once
#include <windows.h>
#define DEFAULT_CHUNK_SIZE 4 * sizeof(unsigned long int)
#define DEFAULT_INPUT "input.dat"
using namespace std;

class LargeBinaryFileSortClass
{
public:
	LargeBinaryFileSortClass();
	LargeBinaryFileSortClass(string);
	int Sort();
private:
	void DivideIntoSortedParts();
	void CreateNewUnsortedPart(const string& tempFileName, ifstream& inputStream, const unsigned int chunkSize);
	void SortPart(char* memBlock, const unsigned int chunkSize);
	void quickSort(unsigned long int* a, int b, int e);
	string m_fileToSortPath;
	unsigned int partCounter;
};