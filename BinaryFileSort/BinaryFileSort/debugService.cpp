
#include "stdafx.h"
#include "debugService.h"

#define DEFAULT_INPUT "input.dat"
#define TEST_NUMBER_COUNT 11

void DebugService::CreateInputFile()
{
	ofstream ofs;
	ofs.open(DEFAULT_INPUT, ofstream::binary | ofstream::out);
	unsigned long int* inputData = new unsigned long int[TEST_NUMBER_COUNT]{ 16, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5 };
	ofs.write(reinterpret_cast<const char*>(inputData), TEST_NUMBER_COUNT*sizeof(unsigned long int));
	ofs.close();
	delete[] inputData;
}
void DebugService::ShowFile()
{
	ifstream ifs;
	ifs.open(DEFAULT_INPUT, ofstream::binary | ofstream::in);
	if (ifs.is_open())
	{
		size_t readBufferSize = TEST_NUMBER_COUNT * sizeof(unsigned long int);
		char* memblock = new char[readBufferSize];
		ifs.read(memblock, readBufferSize);
		unsigned long int* result = reinterpret_cast<unsigned long int*>(memblock);
		for (int i = 0; i < TEST_NUMBER_COUNT; i++)
		{
			cout << result[i] << " ";
		}
		delete[] memblock;
		ifs.close();
	}
	else
	{
		cout << "file  not found" << endl;
	}
}