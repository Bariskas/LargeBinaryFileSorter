#pragma once

#define DEFAULT_CHUNK_SIZE 5
#define DEFAULT_INPUT "input.dat"


class LargeBinaryFileSortClass
{
public:
	LargeBinaryFileSortClass();
	LargeBinaryFileSortClass(uint32_t chunkSize);
	int Sort(const std::string& inputFileToSortName, const std::string& outputSorterFileName = "defaultOutput.dat");
private:
	int DivideIntoSortedParts(const std::string& inputFileToSortName);
	void CreateNewUnsortedPart(const std::string& tempFileName, std::ifstream& inputStream, const unsigned int chunkSize);
	void SortPart(char* memBlock, const unsigned int chunkSize);
	void quickSort(unsigned long int* a, int b, int e);

	uint32_t m_sortedFilesCount;
	uint32_t m_chunkSize;
};