#pragma once
#include <vector>
#include <string>

class Parser {
public:
	static std::vector<int> parseCSV(const std::string& line);
	static std::vector<int> parseAlgExp(std::string expression);

	static std::string parseToCSV(const std::vector<int>& data);
	static std::string parseToAlgExp(const std::vector<int>& coefficients);
	
	
	static std::vector<int> parsePoly(std::string expression);
};

