#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "ErrorMessages.h"
#include "Parser.h"

//FILES END OF LINE SHOULD BE THE LAST LINE OTHERWISE CODE WILL BREAK

std::string FileHandler::DIRECTORY = "files/";

void FileHandler::checkFileExtension(const std::string& filename, const std::string& extension) {
    if (0 != filename.compare(filename.length() - extension.length(), extension.length(), extension)) {
        throw std::invalid_argument(INVALID_FILE_EXTENSION);
    }
}


FileHandler::FileFormatCSV FileHandler::CSV::readChunk(std::istream& file) {
    FileHandler::FileFormatCSV data;
    std::string line;
    getline(file, line);
    data.outputSet = Parser::parseCSV(line);
    getline(file, line);
    data.inputRange = Parser::parseCSV(line);
    getline(file, line);
    data.numTerms = std::stoi(line);
    return data;
}

FileHandler::FileFormatCSV FileHandler::CSV::read(const std::string& filename) {
    std::ifstream file(DIRECTORY + filename);
    if (file.is_open()) {
        FileHandler::FileFormatCSV data = readChunk(file);
        file.close();
        return data;
    }
    else throw std::invalid_argument(INVALID_FILENAME); //file not found
}

std::vector<FileHandler::FileFormatCSV> FileHandler::CSV::readBulk(const std::string& filename) {
    std::vector<FileHandler::FileFormatCSV> data;
    std::ifstream file(DIRECTORY + filename);
    std::string line;
    if (file.is_open()) {
        while (!file.eof()) 
            data.push_back(readChunk(file));
        file.close();
        return data;
    }
    else throw std::invalid_argument(INVALID_FILENAME);
}

void FileHandler::CSV::write(const std::string& filename, const std::vector<int>& data) {
    std::ofstream file;
    file.open(DIRECTORY + filename);
    for (const auto& value : data) 
        file << value << ',';
    file.close();
}

void FileHandler::CSV::writeBulk(const std::string& filename, const std::vector<std::vector<int>>& data) {
    std::ofstream file;
    file.open(DIRECTORY + filename);
    for (const auto& line : data) {
        for (const auto& value : line)
            file << value << ',';
        file << '\n';
    }
    file.close();
}


FileHandler::FileFormatEXP FileHandler::TXT::readChunk(std::istream& file){
    FileHandler::FileFormatEXP data;
    std::string line;
    getline(file, line);
    data.pCoefficients = Parser::parsePolynomial(line);
    getline(file, line);
    data.inputRange = Parser::parseCSV(line);
    return data;
}

FileHandler::FileFormatEXP FileHandler::TXT::read(const std::string& filename) {
    std::ifstream file(DIRECTORY + filename);
    if (file.is_open()) {
        FileHandler::FileFormatEXP data = readChunk(file);
        file.close();
        return data;
    }
    else throw std::invalid_argument(INVALID_FILENAME);
}

std::vector<FileHandler::FileFormatEXP> FileHandler::TXT::readBulk(const std::string& filename) {
    std::vector<FileHandler::FileFormatEXP> data;
    std::string line;
    std::ifstream file(DIRECTORY + filename);
    if (file.is_open()) {
        while (!file.eof()) 
            data.push_back(readChunk(file));
        file.close();
        return data;
    }
    else throw std::invalid_argument(INVALID_FILENAME);
}

void FileHandler::TXT::write(const std::string& filename, const FileFormatEXP& data) {
    std::ofstream file;
    file.open(DIRECTORY + filename);
    file << Parser::parseToPolynomialString(data.pCoefficients) << '\n';
    file << Parser::parseToCsvString(data.inputRange);
    file.close();
}

void FileHandler::TXT::writeBulk(const std::string& filename, const std::vector<FileFormatEXP>& data) {
    std::ofstream file;
    file.open(DIRECTORY + filename);
    for (const auto& line : data) {
        file << Parser::parseToPolynomialString(line.pCoefficients) << '\n';
        file << Parser::parseToCsvString(line.inputRange);
        if (&line != &data.back()) file << '\n';
    }
    file.close();
}


