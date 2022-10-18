#include "Parser.h"
#include <sstream>
#include <fstream>
#include <iostream>


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

std::vector<int> Parser::parseAlgExp(std::string expression) {
    //2x^4 + 3x^2 - 6x + 87
    return std::vector<int>();;
}

//parses to CSV String so that it can be outputted to console, change the name ???
std::string Parser::parseToCSV(const std::vector<int>& data) {
    std::string stringCSV {'{'};
    for (const auto& i : data) {
        stringCSV += std::to_string(i);
        if (&i != &data.back())
            stringCSV += ',';
    }
    stringCSV += '}';
    return stringCSV;
}

//remove this function
std::vector<int> Parser::parsePoly(std::string expression)
{
    return parseCSV(expression);
}
