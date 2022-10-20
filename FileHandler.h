#pragma once
#include <string>
#include <vector>

namespace FileHandler {
	extern std::string DIRECTORY;

	//csv (output set) file format for reading only
	struct FileFormatCSV {
		std::vector<int> outputSet;
		std::vector<int> inputRange {0,0};
		int numTerms{ 0 };
		
		FileFormatCSV() {};
		FileFormatCSV(std::vector<int> outputSet, std::vector<int> inputRange, int numTerms) {
			this->outputSet = outputSet;
			this->inputRange = inputRange;
			this->numTerms = numTerms;
		}
	};

	//expression file format (read/write both)
	struct FileFormatEXP {
		std::vector<int> pCoefficients;
		std::vector<int> inputRange;

		FileFormatEXP() {};
		FileFormatEXP(std::vector<int> pCoefficients, std::vector<int> inputRange) {
			this->pCoefficients = pCoefficients;
			this->inputRange = inputRange;
		}
	};

	void checkFileExtension(const std::string& filename, const std::string& extension);
	
	//for output set files
	namespace CSV {
		FileFormatCSV readChunk(std::istream& file);
		FileFormatCSV read(const std::string& filename);
		std::vector<FileFormatCSV> readBulk(const std::string& filename);

		void write(const std::string& filename, const std::vector<int>& data);
		void writeBulk(const std::string& filename, const std::vector< std::vector<int>>& data);
	}
	//for expression files
	namespace TXT {
		FileFormatEXP readChunk(std::istream& file);
		FileFormatEXP read(const std::string& filename);
		std::vector<FileFormatEXP> readBulk(const std::string& filename);

		void write(const std::string& filename, const FileFormatEXP& data);
		void writeBulk(const std::string& filename, const std::vector<FileFormatEXP>& data);
	}
}





