#include "PolynomialEvaluator.h"
#include <stdexcept>

PolynomialEvaluator::PolynomialEvaluator(std::vector<int> coefficients, int startInputRange, int endInputRange) {
	this->polynomial = new Polynomial(coefficients);
	for (int i{ startInputRange }; i <= endInputRange; i++) {
		this->inputSet.push_back(i);
	}
}

void PolynomialEvaluator::evaluate() {
	if (outputSet.size() == 0) {
		for (const int& x : inputSet) {
			outputSet.push_back(polynomial->evaluate(x));
		}
	}
}

PolynomialEvaluator::~PolynomialEvaluator() {
	delete polynomial;
}
