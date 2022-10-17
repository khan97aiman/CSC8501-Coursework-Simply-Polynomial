#include "PolynomialEvaluator.h"

PolynomialEvaluator::PolynomialEvaluator(Polynomial* polynomial, int startInputRange, int endInputRange) {
	this->polynomial = polynomial;
	for (int i{ startInputRange }; i <= endInputRange; i++) {
		this->inputSet.push_back(i);
	}
}

std::vector<int> PolynomialEvaluator::evaluate() {
	if (outputSet.size() == 0) {
		for (const int& x : inputSet) {
			outputSet.push_back(polynomial->evaluate(x));
		}
	}
	return outputSet;
}
