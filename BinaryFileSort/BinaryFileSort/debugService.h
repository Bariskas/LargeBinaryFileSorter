

#pragma once

class DebugService
{
public:
	void CreateInputFile(const std::string& fileName, std::vector<uint32_t>& inputData);
	void ShowFile();
};