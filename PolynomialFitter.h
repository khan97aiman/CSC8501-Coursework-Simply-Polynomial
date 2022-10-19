#pragma once
#include <vector>
#include <iostream>
#include "Polynomial.h"

class PolynomialFitter {
	Polynomial* polynomial = NULL;
	std::vector<int> outputSet;
	std::vector<int> inputSet;
	int numTerms {0};
public:
	int determineDegree();
	PolynomialFitter(std::vector<int> outputSet, int startInputRange, int endInputRange, int numTerms);
	PolynomialFitter(std::vector<int> outputSet, int startInputRange, int endInputRange);
	PolynomialFitter(std::vector<int> outputSet);

	void fit();
	Polynomial* getPolynomial() { return polynomial; }
	~PolynomialFitter();
};

