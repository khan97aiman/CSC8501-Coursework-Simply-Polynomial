#include "PolynomialEvaluator.h"
#include <stdexcept>
#include "matplotlibcpp.h"


PolynomialEvaluator::PolynomialEvaluator(std::vector<int> coefficients, int startInputRange, int endInputRange) {
	this->polynomial = new Polynomial(coefficients);
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
//
//void PolynomialEvaluator::plot() {
//	if (outputSet.size() == 0) { //redundant
//		evaluate();
//	}
//	matplotlibcpp::plot(inputSet, outputSet, "-o");
//	matplotlibcpp::show("minimal.pdf");
//}
