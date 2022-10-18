#pragma once
#include <vector>
#include <string>

namespace Parser {

	namespace PolynomialHelper {
		void polynomialLexing(std::string& expression, char delimiter); //attaches extra content to expression, in this case adds + sign before every -
		std::vector<std::string> tokenize(const std::string& expression, char delimiter); //separate poly terms
		void termLexing(std::vector<std::string>& tokens); //lexer attaches extra content to tokens, in this case tokens are terms, lexer attaches x and exponent information to terms 
		std::vector<int> extractCoefficents(const std::vector<std::string>& tokens);
	}
	
	std::vector<int> parseCSV(const std::string& line);
	std::vector<int> parsePolynomial(const std::string& expression);
	std::string parseToCsvString(const std::vector<int>& data);
	std::string parseToPolynomialString(const std::vector<int>& coefficients);
};

