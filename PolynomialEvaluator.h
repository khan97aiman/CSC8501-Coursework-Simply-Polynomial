#pragma once
#include "Polynomial.h"
#include <iostream>
class PolynomialEvaluator {
	Polynomial* polynomial;
	std::vector<int> inputSet;
	std::vector<int> outputSet;
public:
	PolynomialEvaluator(std::vector<int> coefficients, int startInputRange, int endInputRange);
	std::vector<int> evaluate(); //change to void???
	std::vector<int> getOutput() { return outputSet; }
	~PolynomialEvaluator() {
		std::cout << "Destructing Polynomial Evaluator\n";
		delete polynomial;
	}
	//void plot();
};

