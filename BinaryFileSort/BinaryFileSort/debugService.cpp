#include "stdafx.h"

#include "debugService.h"

#define DEFAULT_INPUT "input.dat"
#define TEST_NUMBER_COUNT 11

using namespace std;

void DebugService::CreateInputFile(const string& fileName, vector<uint32_t>& inputData)
{
	ofstream ofs;
	ofs.open(fileName, ofstream::binary | ofstream::out);
	//array<uint32_t, TEST_NUMBER_COUNT> inputData = { 16, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5 };
	ofs.write(reinterpret_cast<const char*>(&inputData[0]), inputData.size()*sizeof(uint32_t));
	//vector<uint32_t> inputDataVector(inputData.begin(), inputData.end());
	//ostream_iterator<std::uint32_t> output_iterator(ofs, "");
	//std::copy(inputData.begin(), inputData.end(), output_iterator);
	ofs.close();
}
void DebugService::ShowFile()
{
	ifstream ifs;
	ifs.open(DEFAULT_INPUT, ofstream::binary | ofstream::in);
	if (ifs.is_open())
	{
		size_t readBufferSize = TEST_NUMBER_COUNT * sizeof(uint32_t);
		char* memblock = new char[readBufferSize];
		ifs.read(memblock, readBufferSize);
		uint32_t* result = reinterpret_cast<uint32_t*>(memblock);
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