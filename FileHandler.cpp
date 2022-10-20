#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "ErrorMessages.h"
#include "Parser.h"
#include "HelperFunctions.h"
#include "Constants.h"

//FILES END OF LINE SHOULD BE THE LAST LINE OTHERWISE CODE WILL BREAK
std::string FileHandler::DIRECTORY = "files/";
std::string FileHandler::CSV::FOLDER = "csv/";
std::string FileHandler::TXT::FOLDER = "txt/";


void FileHandler::checkFileExtension(const std::string& filename, const std::string& extension) {
    if (0 != filename.compare(filename.length() - extension.length(), extension.length(), extension)) {
        throw std::invalid_argument(INVALID_FILE_EXTENSION + extension);
    }
}


FileHandler::FileFormatCSV FileHandler::CSV::readChunk(std::istream& file) {
    FileHandler::FileFormatCSV data;
    std::string line;
    
    getline(file, line);
    if (line.find(UNKNOWN) != std::string::npos) throw std::invalid_argument(INVALID_INPUT + line);
    data.outputSet = Parser::parseCSV(line); 
    
    getline(file, line);
    if (line.find(UNKNOWN) == std::string::npos) data.inputRange = Parser::parseCSV(line);
    
    getline(file, line);
    if (line.find(UNKNOWN) == std::string::npos) data.numTerms = std::stoi(line);
    
    return data;
}

std::vector<FileHandler::FileFormatCSV> FileHandler::CSV::read(const std::string& filename) {
    checkFileExtension(filename, ".csv");
    std::vector<FileHandler::FileFormatCSV> data;
    std::ifstream file(DIRECTORY + FOLDER + filename);
    std::string line;
    if (file.is_open()) {
        try {
            while (!file.eof())
            data.push_back(readChunk(file));
        }
        catch (const std::exception& e) {
            handleException(e);
            file.close();
        }
        return data;
    }
    else throw std::invalid_argument(FILE_NOT_FOUND);
}

void FileHandler::CSV::write(const std::string& filename, const std::vector<std::vector<int>>& data) {
    checkFileExtension(filename, ".csv");
    std::ofstream file;
    file.open(DIRECTORY + FOLDER + filename);
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

std::vector<FileHandler::FileFormatEXP> FileHandler::TXT::read(const std::string& filename) {
    checkFileExtension(filename, ".txt");
    std::vector<FileHandler::FileFormatEXP> data;
    std::string line;
    std::ifstream file(DIRECTORY + FOLDER + filename);
    if (file.is_open()) {
        try {
            while (!file.eof())
                data.push_back(readChunk(file));
        }
        catch (const std::exception& e) {
            handleException(e);
            file.close();
        }
        return data;
    }
    else throw std::invalid_argument(FILE_NOT_FOUND);
}

void FileHandler::TXT::write(const std::string& filename, const std::vector<FileFormatEXP>& data) {
    checkFileExtension(filename, ".txt");
    std::ofstream file;
    file.open(DIRECTORY + FOLDER + filename);
    try {
        for (const auto& line : data) {
            file << Parser::parseToPolynomialString(line.pCoefficients) << '\n';
            file << Parser::parseToCsvString(line.inputRange);
            if (&line != &data.back()) file << '\n';
        }
    }
    catch (const std::exception& e) {
        handleException(e);
        file.close();
    }
}

FileHandler::FileFormatCSV::FileFormatCSV(std::vector<int> outputSet, std::vector<int> inputRange, int numTerms) {
    this->outputSet = outputSet;
    this->inputRange = inputRange;
    this->numTerms = numTerms;
}

FileHandler::FileFormatEXP::FileFormatEXP(std::vector<int> pCoefficients, std::vector<int> inputRange) {
    this->pCoefficients = pCoefficients;
    this->inputRange = inputRange;
}
