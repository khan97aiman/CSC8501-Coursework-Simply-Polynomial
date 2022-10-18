#include "Parser.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <regex>


void Parser::polynomialLexing(std::string& expression, char delimiter) {
    auto i = expression.begin();
    while ((i = std::find(i, expression.end(), '-')) != expression.end()) {
        i = expression.insert(i, delimiter) + 2;
    }
}

std::vector<std::string> Parser::tokenize(const std::string& expression, char delimiter) {
    std::istringstream stream(expression);
    std::string token;
    std::vector<std::string> tokens;
    while (getline(stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void Parser::termLexing(std::vector<std::string>& tokens) {
    for (auto& token : tokens) {
        //if token does not contain x
        if (token.find('x') == std::string::npos) {
            token += "x^0";
        }
        //if token does not contain ^
        else if (token.find('^') == std::string::npos) {
            token += "^1";
        }
        else {
            if (token.find('x') == 0) token = "1" + token;
        }
    }
}

//this function extracts coefficient and exponent information from expression tokens
std::vector<int> Parser::extractCoefficents(const std::vector<std::string>& tokens) {
    std::vector<int> coefficients(5, 0);; //5 depends of max poly degree (4 degree corresponds to 5 terms) //change this to maximum exponent of the poly string
    for (const auto& token : tokens) {
        std::stringstream tokenStream(token);
        std::string coefficient, exponent;
        std::getline(tokenStream, coefficient, 'x');
        std::getline(tokenStream, exponent, 'x');
        
        //reverse this order x^2 should be 1,0,0 not 0,0,1
        coefficients[4 - (exponent[1] - '0')] += std::stoi(coefficient);
    }
    return coefficients;
}

std::vector<int> Parser::parseCSV(const std::string& line)
{
    std::istringstream linestream(line);
    std::string item;
    std::vector<int> data;
    while (getline(linestream, item, ',')) {
        data.push_back(std::stoi(item));
    }
    return data;
    //if data is not integer, handle invalid inputs in file, that is already handled by stoi, just catch it in main
}

std::vector<int> Parser::parsePolynomial(const std::string& expression) {
    std::string pExpression = std::regex_replace(expression, std::regex("\\s+"), "");
    polynomialLexing(pExpression, '+');
    std::vector<std::string> tokens = tokenize(pExpression, '+');
    termLexing(tokens);
    //check if polynomial is valid???? should i check in polynomial class?? yes
    return extractCoefficents(tokens);
}

//parses to CSV String so that it can be outputted to console, change the name ???
std::string Parser::parseToCsvString(const std::vector<int>& data) {
    std::string stringCSV;
    for (const auto& i : data) {
        stringCSV += std::to_string(i);
        if (&i != &data.back())
            stringCSV += ',';
    }
    return stringCSV;
}

std::string Parser::parseToPolynomialString(const std::vector<int>& coefficients) {
    std::string polynomial;
    int exp{ coefficients.size() - 1};
    for (const auto& coeff : coefficients) {
        if (coeff) {
            exp > 1 ? polynomial += coeff + "x^" + exp : exp ? polynomial += coeff + 'x' : polynomial += coeff;
        }
        exp--;
    }
    return polynomial;
}
