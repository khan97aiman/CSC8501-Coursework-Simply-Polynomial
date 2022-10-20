#include "HelperFunctions.h"
#include <iostream>
#include <regex>
#include <numeric> // std::inner_product
#include "Constants.h"


std::string handleUserInput(bool prompt) {
	if (prompt) std::cout << "Waiting for your input: ";
	std::string input;
	std::getline(std::cin, input);
	return input;
}

void handleInvalidInput() {
	std::cout << "-----------------------------------------------------------------" << '\n';
	std::cout << "                    Command/Input is Invalid!                    " << '\n';
	std::cout << "-----------------------------------------------------------------" << '\n';
}

void handleException(const std::exception& e) {
    std::cout << "-----------------------------------------------------------------" << '\n';
    std::cout << "Exception Occured: " << e.what() << '\n';
    std::cout << "-----------------------------------------------------------------" << '\n';
}

bool isPolynomialValid(std::string polynomialString) {
	std::regex pattern("^([-+]?([0-9]+)?(x(\\^[+]?[0-9]+)?)?)+");
	return std::regex_match(polynomialString, pattern);
}

bool isPolynomialValid(std::vector<int> coefficients) {
    if (coefficients.size() > MAX_POLYNOMIAL_DEGREE + 1) return false;
    for (const auto& coeff : coefficients) {
        if (&coeff != &coefficients.back()) {
            if (coeff > 9 || coeff < -9) return false;
        }
        else {
            if (coeff > 1000 || coeff < -1000) return false;
        }
    }
    return true;
}

bool isConstant(const std::vector<int>& v) {
	return std::adjacent_find(v.begin() + 1, v.end(), std::not_equal_to<>()) == v.end();
 }

std::vector<std::vector<double>> mult(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2) {
    if (matrix1[0].size() != matrix2.size()) {
        throw std::invalid_argument("Matrix Multiplication is not possible");
    }
    std::vector<std::vector<double>> result(matrix1.size(), std::vector<double>(matrix2[0].size(), 0));
    std::vector<std::vector<double>> matrix2_t = transpose(matrix2);

    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix2_t.size(); j++) 
            result[i][j] = std::inner_product(matrix1[i].begin(), matrix1[i].end(), matrix2_t[j].begin(), 0.0);   
    }
    return result;
}
std::vector<int> mult(const std::vector<std::vector<double>>& matrix, const std::vector<int>& vect) {
    if (matrix[0].size() != vect.size()) {
        throw std::invalid_argument("Matrix Multiplication is not possible");
    }
    std::vector<int> result(matrix.size());

    for (int i = 0; i < matrix.size(); i++) {
        result[i] = std::round(std::inner_product(matrix[i].begin(), matrix[i].end(), vect.begin(), 0.0));
    }
    return result;
}

//From stackoverflow
double determinant(const std::vector<std::vector<double>>& vect) {
    if (vect.size() != vect[0].size()) {
        throw std::invalid_argument("Matrix is not quadratic");
    }
    int dimension = vect.size();

    if (dimension == 0) {
        return 1;
    }

    if (dimension == 1) {
        return vect[0][0];
    }

    //Formula for 2x2-matrix
    if (dimension == 2) {
        return vect[0][0] * vect[1][1] - vect[0][1] * vect[1][0];
    }

    double result = 0;
    int sign = 1;
    for (int i = 0; i < dimension; i++) {

        //Submatrix
        std::vector<std::vector<double>> subVect(dimension - 1, std::vector<double>(dimension - 1));
        for (int m = 1; m < dimension; m++) {
            int z = 0;
            for (int n = 0; n < dimension; n++) {
                if (n != i) {
                    subVect[m - 1][z] = vect[m][n];
                    z++;
                }
            }
        }

        //recursive call
        result = result + sign * vect[0][i] * determinant(subVect);
        sign = -sign;
    }

    return result;
}
std::vector<std::vector<double>> transpose(const std::vector<std::vector<double>>& matrix) {

    //Transpose-matrix: height = width(matrix), width = height(matrix)
    std::vector<std::vector<double>> solution(matrix[0].size(), std::vector<double>(matrix.size()));

    //Filling solution-matrix
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[0].size(); j++) {
            solution[j][i] = matrix[i][j];
        }
    }
    return solution;
}
std::vector<std::vector<double>> cofactor(const std::vector<std::vector<double>>& vect) {
    if (vect.size() != vect[0].size()) {
        throw std::runtime_error("Matrix is not quadratic/square");
    }

    std::vector<std::vector<double>> solution(vect.size(), std::vector<double>(vect.size()));
    std::vector<std::vector<double>> subVect(vect.size() - 1, std::vector<double>(vect.size() - 1));

    for (std::size_t i = 0; i < vect.size(); i++) {
        for (std::size_t j = 0; j < vect[0].size(); j++) {

            int p = 0;
            for (size_t x = 0; x < vect.size(); x++) {
                if (x == i) {
                    continue;
                }
                int q = 0;

                for (size_t y = 0; y < vect.size(); y++) {
                    if (y == j) {
                        continue;
                    }

                    subVect[p][q] = vect[x][y];
                    q++;
                }
                p++;
            }
            solution[i][j] = pow(-1, i + j) * determinant(subVect);
        }
    }
    return solution;
}
std::vector<std::vector<double>> inverse(const std::vector<std::vector<double>>& vect) {
    double determinant_ = determinant(vect);
    if (determinant_ == 0) {
        throw std::runtime_error("Determinant is 0: Matrix Inverse does not exist");
    }

    double d = 1.0 / determinant_;
    std::vector<std::vector<double>> solution(vect.size(), std::vector<double>(vect.size()));

    for (size_t i = 0; i < vect.size(); i++) {
        for (size_t j = 0; j < vect.size(); j++) {
            solution[i][j] = vect[i][j];
        }
    }

    solution = cofactor(solution);

    for (size_t i = 0; i < vect.size(); i++) {
        for (size_t j = 0; j < vect.size(); j++) {
            solution[j][i] *= d; //accessing transpose
        }
    }

    return solution;
}

