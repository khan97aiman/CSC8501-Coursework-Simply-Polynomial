#pragma once
#include <vector>
#include <string>

class Parser {
	//utils functionality 
	//check if polynomial is valid --> do it after you have parsed it
	static void polynomialLexing(std::string& expression, char delimiter); //attaches extra content to expression, in this case adds + sign before every -
	static std::vector<std::string> tokenize(const std::string& expression, char delimiter); //separate poly terms
	static void termLexing(std::vector<std::string>& tokens); //lexer attaches extra content to tokens, in this case tokens are terms, lexer attaches x and exponent information to terms 
	static std::vector<int> extractCoefficents(const std::vector<std::string>& tokens);

public:
	static std::vector<int> parseCSV(const std::string& line);
	static std::vector<int> parsePolynomial(const std::string& expression);

	static std::string parseToCsvString(const std::vector<int>& data);
	static std::string parseToPolynomialString(const std::vector<int>& coefficients);
};

