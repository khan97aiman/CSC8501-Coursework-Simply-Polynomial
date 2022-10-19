#include "PolynomialFitter.h"

PolynomialFitter::PolynomialFitter(std::vector<int> outputSet, int startInputRange, int endInputRange, int numTerms) {
	this->outputSet = outputSet;
	//could be a lambda function - similar code in poly evaluator constructor
	for (int i{ startInputRange }; i <= endInputRange; i++) {
		this->inputSet.push_back(i);
	}
	this->numTerms = numTerms;
}

PolynomialFitter::PolynomialFitter(std::vector<int> outputSet, int startInputRange, int endInputRange) {
	this->outputSet = outputSet;
	//could be a lambda function - similar code in poly evaluator constructor
	for (int i{ startInputRange }; i <= endInputRange; i++) {
		this->inputSet.push_back(i);
	}
}

PolynomialFitter::PolynomialFitter(std::vector<int> outputSet) {
	this->outputSet = outputSet;
}

void PolynomialFitter::fit() {
}

PolynomialFitter::~PolynomialFitter() {
	std::cout << "Destructing Polynomial Fitter\n";
	delete polynomial;
}
