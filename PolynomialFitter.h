#pragma once
#include <vector>
#include <iostream>
#include "Polynomial.h"

class PolynomialFitter {
	Polynomial* polynomial = NULL;
	std::vector<int> outputSet;
	std::vector<int> inputSet;
	int numTerms {0};

	//helper functions
	void fitGivenInputSet();
public:
	int determineDegree();
	PolynomialFitter(std::vector<int> outputSet, int startInputRange, int endInputRange, int numTerms);

	void fit();
	Polynomial* getPolynomial() { return polynomial; }
	std::vector<int> getInputSetRange() { return std::vector<int>{inputSet.front(), inputSet.back()}; }
	~PolynomialFitter();
};

