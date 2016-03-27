#include "stdafx.h"
#include "LargeBinaryFileSortClass.h"

LargeBinaryFileSortClass::LargeBinaryFileSortClass(string fileToSortPath = DEFAULT_INPUT)
	: m_fileToSortPath(fileToSortPath)
{

}
LargeBinaryFileSortClass::LargeBinaryFileSortClass()
	: m_fileToSortPath(DEFAULT_INPUT)
{

}

int LargeBinaryFileSortClass::Sort()
{
	DivideIntoSortedParts();
	return 0;
}

void LargeBinaryFileSortClass::DivideIntoSortedParts()
{
	int fileCounter = 0;

	ifstream inputFileToSortStream(m_fileToSortPath, ofstream::binary | ofstream::in);
	if (inputFileToSortStream.is_open())
	{
		bool endOfFile = false;
		while (!endOfFile)
		{
			int chunkSize = 0;
			int current = inputFileToSortStream.tellg();
			inputFileToSortStream.seekg(inputFileToSortStream.cur, inputFileToSortStream.end);
			int least = inputFileToSortStream.tellg();
			inputFileToSortStream.seekg(current, 0);
			least - current < DEFAULT_CHUNK_SIZE ? chunkSize = least - current - 1 : chunkSize = DEFAULT_CHUNK_SIZE;

			if (chunkSize == 0)
			{
				endOfFile = true;
				continue;
			}

			string tempFileName = "temp";
			tempFileName = tempFileName + to_string(fileCounter++) + ".txt";
			CreateNewUnsortedPart(tempFileName, inputFileToSortStream, chunkSize);
		}
	}
	else
	{
		cout << "failed open file" << endl;
	}
	inputFileToSortStream.close();
}

void LargeBinaryFileSortClass::CreateNewUnsortedPart(const string& tempFileName, ifstream& inputStream, const unsigned int chunkSize)
{
	char* memBlock = new char[chunkSize];
	ofstream ofs(tempFileName, ofstream::binary | ofstream::out);
	
	inputStream.read(memBlock, chunkSize);

	SortPart(memBlock, chunkSize);

	ofs.write(memBlock, chunkSize);

	delete[] memBlock;
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