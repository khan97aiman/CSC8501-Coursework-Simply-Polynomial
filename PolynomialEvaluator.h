#pragma once
#include "Polynomial.h"
#include <iostream>
class PolynomialEvaluator {
	Polynomial* polynomial = NULL;
	std::vector<int> inputSet;
	std::vector<int> outputSet;
public:
	PolynomialEvaluator(std::vector<int> coefficients, int startInputRange, int endInputRange);
	std::vector<int> evaluate(); //change to void???
	std::vector<int> getOutput() { return outputSet; }
	~PolynomialEvaluator() {
		delete polynomial;
	}
	//void plot();
};

