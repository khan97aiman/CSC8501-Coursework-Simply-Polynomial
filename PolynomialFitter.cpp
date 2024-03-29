#include "PolynomialFitter.h"
#include <numeric>   
#include "HelperFunctions.h"

void PolynomialFitter::fitGivenInputSet() {
	std::vector<std::vector<double>> A; 
	int degree{ determineDegree() };
	for (const auto& x: inputSet) {
		std::vector<double> row;
		for (int exp{ degree }; exp >= 0; exp--)
			row.push_back((int)pow(x, exp));
		A.push_back(row);
	}
	std::vector<int> coefficients = mult(mult(inverse(mult(transpose(A), A)), transpose(A)), outputSet);
	polynomial = new Polynomial(coefficients);
}

void PolynomialFitter::fitWithoutInputSet() {
	//create an input set starting from zero
	int num = outputSet.size();
	for (int i{0}; i < num; i++) {
		this->inputSet.push_back(i);
	}
	fitGivenInputSet();
}

int PolynomialFitter::determineDegree() {
	int degree{ 0 };
	std::vector<int> differential { outputSet };
	bool isDifferentialConst = isConstant(differential);
	while (!isDifferentialConst) {
		std::vector<int> result(differential.size());
		std::adjacent_difference(differential.begin(), differential.end(), result.begin());
		differential.assign(result.begin() + 1, result.end());
		isDifferentialConst = isConstant(differential);
		degree++;
	}
	return degree;
}

PolynomialFitter::PolynomialFitter(std::vector<int> outputSet, int startInputRange, int endInputRange, int numTerms) {
	this->outputSet = outputSet;
	if (startInputRange != 0 || endInputRange != 0) {
		for (int i{ startInputRange }; i <= endInputRange; i++) {
			this->inputSet.push_back(i);
		}
	}
	this->numTerms = numTerms;
}

void PolynomialFitter::fit() {
	if (inputSet.size() > 0)
		fitGivenInputSet();
	else
		fitWithoutInputSet();
	/*if (numTerms && polynomial->numberOfTerms() != numTerms)
		throw std::runtime_error("Could not fit!");*/
}

PolynomialFitter::~PolynomialFitter() {
	delete polynomial;
}