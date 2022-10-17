#pragma once
#include <string>
#include <vector>
//DISCUSS IF THIS SHOULD BE A CLASS?
class FileHandler {
public:
	static std::vector<int> read(const std::string filename);
	static void write(const std::string filename, const std::vector<int>& data);
	static void checkFileExtension(std::string filename);
	static std::vector< std::vector<int>> readBulk(const std::string filename);
	static void writeBulk(const std::string filename, const std::vector< std::vector<int>>& data);
};

