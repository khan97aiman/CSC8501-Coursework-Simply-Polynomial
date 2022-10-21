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
	void fitWithoutInputSet();
public:
	PolynomialFitter(std::vector<int> outputSet, int startInputRange, int endInputRange, int numTerms);
	int determineDegree();
	void fit();
	Polynomial* getPolynomial() { return polynomial; }
	std::vector<int> getInputSetRange() { return std::vector<int>{inputSet.front(), inputSet.back()}; }
	~PolynomialFitter();
};

