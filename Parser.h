#pragma once
#include <vector>
#include <string>

namespace Parser {

	namespace PolynomialHelper {
		/*
		* polynomialLexing(): Attaches extra content to polynomial expression, in this case adds '+' sign before every '-'
		* tokenize(): Separates polyonimal terms by '+' signs
		* termLexing(): Attaches extra content to tokens, in this case tokens are terms, termLexing() attaches 'x' and exponent information to terms wherever missing
		* extract(): Extracts coefficients from the tokens
		*/
		void polynomialLexing(std::string& expression, char delimiter); 
		std::vector<std::string> tokenize(const std::string& expression, char delimiter); 
		void termLexing(std::vector<std::string>& tokens);  
		std::vector<int> extract(const std::vector<std::string>& tokens);
	}
	std::vector<int> parseCSV(const std::string& line);
	std::vector<int> parsePolynomial(const std::string& expression);
	std::string parseToCsvString(const std::vector<int>& data);
	void parseToPolynomialTerm(const int& coeff, const int& exp, std::string& polynomial, const std::vector<int>& coefficients);
	std::string parseToPolynomialString(const std::vector<int>& coefficients);
};

