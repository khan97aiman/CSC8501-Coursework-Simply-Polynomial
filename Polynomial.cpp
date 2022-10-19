#include "Polynomial.h"
#include <iostream>
#include <numeric> // std::inner_product

Polynomial::Polynomial(std::vector<int> coefficients) {
	//CHECK COEFFICIENT RANGES 
	//get index of first non zero element
	int index = 0;
	for (; index < coefficients.size(); index++){
		if (coefficients[index] > 0) 
			break;
	}
	for (size_t i = index; i < coefficients.size(); i++) {
		this->coefficients.push_back(coefficients[i]);
	}
}

Polynomial::Polynomial(const Polynomial& p) {
	this->coefficients = p.coefficients;
}

const int Polynomial::evaluate(int x) {
	std::vector<int> xVector;
	for (int exp{ degree() }; exp >= 0; exp--) {
		xVector.push_back((int)pow(x, exp));
	}
	return std::inner_product(coefficients.begin(), coefficients.end(), xVector.begin(), 0);
}

const bool Polynomial::operator==(const Polynomial& p) {
	return this->coefficients == p.coefficients;
}
