#pragma once
#include "Polynomial.h"
class PolynomialEvaluator {
	Polynomial* polynomial;
	std::vector<int> inputSet;
	std::vector<int> outputSet;
public:
	PolynomialEvaluator(Polynomial* polynomial, int startInputRange, int endInputRange);
	std::vector<int> evaluate();
};

