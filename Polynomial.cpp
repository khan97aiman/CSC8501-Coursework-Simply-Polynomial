#include "Polynomial.h"
#include <iostream>
#include <numeric> // std::inner_product

Polynomial::Polynomial(std::vector<int> coefficients) {
	this->coefficients = coefficients;
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
