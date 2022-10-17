#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "ErrorMessages.h"
#include "Parser.h"

void FileHandler::checkFileExtension(std::string filename) {
    std::string extension = ".csv";
    if (0 != filename.compare(filename.length() - extension.length(), extension.length(), extension)) {
        throw std::invalid_argument(INVALID_FILE_EXTENSION);
    }
}

std::vector<int> FileHandler::read(const std::string filename) {
    std::string line;
    std::ifstream file(filename);
    if (file.is_open()) {
        getline(file, line);
        file.close();
        return Parser::parseCSV(line);
    }
    else throw std::invalid_argument(INVALID_FILENAME);
 }

std::vector<std::vector<int>> FileHandler::readBulk(const std::string filename) {
    std::vector<std::vector<int>> data;
    std::string line;
    std::ifstream file(filename);
    if (file.is_open()) {
        while (getline(file, line))
            data.push_back(Parser::parseCSV(line));
        file.close();
        return data;  
    }
    else throw std::invalid_argument(INVALID_FILENAME);
}

void FileHandler::write(const std::string filename, const std::vector<int>& data) {
    std::ofstream file;
    file.open(filename);
    for (const auto& value : data) 
        file << value << ',';
    file.close();
}

void FileHandler::writeBulk(const std::string filename, const std::vector<std::vector<int>>& data) {
    std::ofstream file;
    file.open(filename);
    for (const auto& line : data) {
        for (const auto& value : line)
            file << value << ',';
        file << '\n';
    }
    file.close();
}


