#include "HelperFunctions.h"
#include <iostream>
#include <regex>

std::string handleUserInput(bool prompt) {
	if (prompt) std::cout << "Waiting for your input: ";
	std::string input;
	std::getline(std::cin, input);
	return input;
}

void handleInvalidInput() {
	std::cout << "-----------------------------------------------------------------" << '\n';
	std::cout << "                    Command/Input is Invalid!                    " << '\n';
	std::cout << "-----------------------------------------------------------------" << '\n';
}

bool isPolynomialValid(std::string polynomialString) {
	std::regex pattern("^([-+]?([0-9]+)?(x(\\^[+]?[0-9]+)?)?)+");
	return std::regex_match(polynomialString, pattern);
}
