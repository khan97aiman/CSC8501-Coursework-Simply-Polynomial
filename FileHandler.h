#pragma once
#include <string>
#include <vector>

namespace FileHandler {
	extern std::string DIRECTORY;

	//csv (output set) file format for reading only
	struct FileFormatCSV {
		std::vector<int> outputSet;
		std::vector<int> inputRange;
		int numTerms{ 0 };
		
		FileFormatCSV() {};
		FileFormatCSV(std::vector<int> outputSet, std::vector<int> inputRange, int numTerms);
	};

	//expression file format (read/write both)
	struct FileFormatEXP {
		std::vector<int> pCoefficients;
		std::vector<int> inputRange;

		FileFormatEXP() {};
		FileFormatEXP(std::vector<int> pCoefficients, std::vector<int> inputRange);
	};

	void checkFileExtension(const std::string& filename, const std::string& extension);
	
	//for output set files
	namespace CSV {
		extern std::string FOLDER;

		FileFormatCSV readChunk(std::istream& file);
		std::vector<FileFormatCSV> read(const std::string& filename);
		void write(const std::string& filename, const std::vector< std::vector<int>>& data);
	}

	//for expression files
	namespace TXT {
		extern std::string FOLDER;

		FileFormatEXP readChunk(std::istream& file);
		std::vector<FileFormatEXP> read(const std::string& filename);
		void write(const std::string& filename, const std::vector<FileFormatEXP>& data);
	}
}





