#include "Parser.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <regex>


void Parser::PolynomialHelper::polynomialLexing(std::string& expression, char delimiter) {
    auto i = expression.begin();
    while ((i = std::find(i, expression.end(), '-')) != expression.end()) {
        i = expression.insert(i, delimiter) + 2;
    }
}

std::vector<std::string> Parser::PolynomialHelper::tokenize(const std::string& expression, char delimiter) {
    std::istringstream stream(expression);
    std::string token;
    std::vector<std::string> tokens;
    while (getline(stream, token, delimiter)) {
        if (token.size())
            tokens.push_back(token);
    }
    return tokens;
}

//MORE THAN 10 LINES OF CODE MODIFY IT
void Parser::PolynomialHelper::termLexing(std::vector<std::string>& tokens) {
    //adds x^0 to constant terms, ^1 to x term, and 
    for (auto& token : tokens) {
        //if token does not contain x
        if (token.find('x') == std::string::npos) {
            token += "x^0";
        }
        //if token does not contain ^
        else if (token.find('^') == std::string::npos) {
            token += "^1";
        }
        //if x is the first char
        if (token.find('x') == 0) token = "1" + token;

        //if -x are first characters
        if (token.find('-') == 0 && token.find('x') == 1) token.insert(1, "1");
    }
}

//this function extracts coefficient and exponent information from expression tokens
std::vector<int> Parser::PolynomialHelper::extractCoefficents(const std::vector<std::string>& tokens) {
    std::vector<int> coefficients(5, 0);; //5 depends of max poly degree (4 degree corresponds to 5 terms) //change this to maximum exponent of the poly string
    for (const auto& token : tokens) {
        std::stringstream tokenStream(token);
        std::string coefficient, exponent;
        std::getline(tokenStream, coefficient, 'x');
        std::getline(tokenStream, exponent, 'x');

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
    PolynomialHelper::polynomialLexing(pExpression, '+');
    std::vector<std::string> tokens = PolynomialHelper::tokenize(pExpression, '+');
    PolynomialHelper::termLexing(tokens);
    //check if polynomial is valid???? should i check in polynomial class?? yes
    return PolynomialHelper::extractCoefficents(tokens);
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


//MORE THAN 10 LINES OF CODE
std::string Parser::parseToPolynomialString(const std::vector<int>& coefficients) {
    std::string polynomial;
    int exp{ (int)coefficients.size() - 1};
    for (const auto& coeff : coefficients) {
        if (coeff) {
            //update this line, because 0, 0, 1, 0, 0 prints +x^2 and not x^2
            if (coeff > 0 && &coeff != &coefficients.front()) polynomial += '+';
            std::string c;
            if (coeff == 1 && &coeff != &coefficients.back()) c = "";
            else if (coeff == -1) c = "-";
            else c = std::to_string(coeff);
            exp > 1 ? polynomial += c + "x^" + std::to_string(exp) : exp ? polynomial += c + 'x' : polynomial += c;
        }
        exp--;
    }
    return polynomial;
}
