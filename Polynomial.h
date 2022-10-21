#pragma once
#include <string>
#include <vector>
class Polynomial {
	std::vector<int> coefficients;
public:
	Polynomial(std::vector<int> coefficients);
	Polynomial(const Polynomial& p);
	const bool operator==(const Polynomial& p);
	const int degree() { return (int)coefficients.size() - 1; }
	const std::vector<int> getCoefficients() { return coefficients; }
	const int numberOfTerms();
	const int evaluate(int x);
};

