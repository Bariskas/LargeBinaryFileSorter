#include "stdafx.h"
#include "LargeBinaryFileSortClass.h"

using namespace std;

LargeBinaryFileSortClass::LargeBinaryFileSortClass(uint32_t chunkSize)
	: m_chunkSize(chunkSize), m_sortedFilesCount(0)
{

}
LargeBinaryFileSortClass::LargeBinaryFileSortClass()
	: m_chunkSize(DEFAULT_CHUNK_SIZE), m_sortedFilesCount(0)
{

}

int LargeBinaryFileSortClass::Sort(const std::string& inputFileToSortName, const std::string& outputSorterFileName)
{
	DivideIntoSortedParts(inputFileToSortName);
	m_sortedFilesCount++;
	return 0;
}

int LargeBinaryFileSortClass::DivideIntoSortedParts(const std::string& inputFileToSortName)
{
	uint32_t fileCounter = 0;

	ifstream inputFileToSortStream(inputFileToSortName, ofstream::binary | ofstream::in);


	if (inputFileToSortStream.is_open())
	{
		bool endOfFile = false;
		size_t bufferSize = 0;

		inputFileToSortStream.seekg(inputFileToSortStream.cur, inputFileToSortStream.end);
		int leastBytes = inputFileToSortStream.tellg();
		inputFileToSortStream.seekg(inputFileToSortStream.beg, 0);
		

		leastBytes < m_chunkSize ? bufferSize = leastBytes : bufferSize = 20;

		while (!endOfFile)
		{
			if (leastBytes == 1)
			{
				endOfFile = true;
				continue;
			}
			ostringstream oss;
			oss << "temp" << m_sortedFilesCount << "_" << fileCounter << ".txt";
			string tempFileName = oss.str();
			CreateNewUnsortedPart(tempFileName, inputFileToSortStream, bufferSize);
			fileCounter++;
			leastBytes -= bufferSize;
			leastBytes < m_chunkSize ? bufferSize = leastBytes - 1 : bufferSize = 20;
		}
	}
	else
	{
		cout << "failed open file" << endl;
	}
	inputFileToSortStream.close();
	return fileCounter;
}

void LargeBinaryFileSortClass::CreateNewUnsortedPart(const string& tempFileName, ifstream& inputStream, const unsigned int bufferSize)
{
	//char* memBlock = new char[bufferSize];
	ofstream ofs(tempFileName, ofstream::binary | ofstream::out);
	
	//inputStream.read(memBlock, bufferSize);

	vector<uint32_t> buffer(bufferSize/4);

	inputStream.read(reinterpret_cast<char*>(&buffer[0]), bufferSize);
	sort(buffer.begin(), buffer.end());

	ofs.write(reinterpret_cast<char*>(&buffer[0]), bufferSize);

	//delete[] memBlock;
	ofs.close();
}

void LargeBinaryFileSortClass::SortPart(char* unsortedData, const unsigned int chunkSize)
{
	unsigned long int* unsortedCastData = reinterpret_cast<unsigned long int*>(unsortedData);
	quickSort(unsortedCastData, 0, chunkSize / 4 - 1);
}

void LargeBinaryFileSortClass::quickSort(unsigned long int* arr, int minLeftEl, int maxRightEl)
{
	int leftEl = minLeftEl, rightEl = maxRightEl;
	int midEl = arr[(leftEl + rightEl) / 2];
	while (leftEl <= rightEl)
	{
		while (arr[leftEl] < midEl)
			leftEl++;
		while (arr[rightEl] > midEl)
			rightEl--;
		if (leftEl <= rightEl)
			swap(arr[leftEl++], arr[rightEl--]);
	}
	if (minLeftEl < rightEl)
		quickSort(arr, minLeftEl, rightEl);
	if (maxRightEl > leftEl)
		quickSort(arr, leftEl, maxRightEl);
}