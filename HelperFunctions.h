#pragma once
#include <string>
#include <vector>
#include <algorithm>

std::string handleUserInput(bool prompt = true);
void handleInvalidInput();
bool isPolynomialValid(std::string polynomialString);
bool isConstant(const std::vector<int>& v);

//USE TEMPLATES HERE???
std::vector<std::vector<double>> mult(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2);
std::vector<int> mult(const std::vector<std::vector<double>>& matrix, const std::vector<int>& vect);

//taken from https://stackoverflow.com/questions/60300482/c-calculating-the-inverse-of-a-matrix
double determinant(const std::vector<std::vector<double>>& vect);
std::vector<std::vector<double>> transpose(const std::vector<std::vector<double>>& matrix);
std::vector<std::vector<double>> cofactor(const std::vector<std::vector<double>>& vect);
std::vector<std::vector<double>> inverse(const std::vector<std::vector<double>>& vect);
