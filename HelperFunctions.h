#pragma once
#include <string>
#include <vector>
#include <algorithm>

std::string handleUserInput(bool prompt = true);
void handleInvalidInput();
bool isPolynomialValid(std::string polynomialString);

//auto isConstant = [](std::vector<int>& v) {
//	return std::adjacent_find(v.begin(), v.end(), std::not_equal_to<>()) == v.end();
//};

bool isConstant(const std::vector<int>& v);
