#include "FittingSimulationHandler.h"
#include "Parser.h"
#include "FileHandler.h"
#include "Constants.h"
#include "ErrorMessages.h"

auto upperCase = [](std::string str) {
	for (auto& c : str) c = toupper(c);
	return str;
};

auto getInput = []() {
	std::string input = handleUserInput(false);
	return upperCase(input) == UNKNOWN ? "0" : input;
};

void FittingSimulationHandler::getInputFromConsole() {
	std::cout << "Please enter your inputs, type 'UNKNOWN' for optional values if you don't want to input: " << "\n\t";

	std::cout << "Enter output set (REQUIRED): "; 
	std::vector<int> outputSet = Parser::parseCSV(handleUserInput(false));

	std::cout << "\tEnter start number of the input range (OPTIONAL): ";
	int num1 = std::stoi(getInput());

	std::cout << "\tEnter finish number of the input range (OPTIONAL): ";
	int num2 = std::stoi(getInput());

	std::cout << "\tEnter number of terms in the polynomial (OPTIONAL): ";
	int numTerms = std::stoi(getInput());

	pFitters.push_back(new PolynomialFitter(outputSet, num1, num2, numTerms));
}

void FittingSimulationHandler::run() {
	for (const auto& fitter : pFitters) {
		fitter->fit();
	}
	//check if number of non zero terms is equal to num terms
}

FittingSimulationHandler::~FittingSimulationHandler() {
	for (const auto& i : pFitters) {
		delete i;
	}
}

void FittingSimulationHandler::getInputFromFile() {
	std::cout << "Filename (REQUIRED '.csv'): ";
	std::string filename = handleUserInput(false);
	std::vector<FileHandler::FileFormatCSV> data = FileHandler::CSV::read(filename);

	for (const auto& e : data) {
		pFitters.push_back(new PolynomialFitter(e.outputSet, e.inputRange[0], e.inputRange[1], e.numTerms));
	}
}

void FittingSimulationHandler::viewOutputOnConsole() {
	std::cout << "-----------------------------------------------------------------" << '\n';
	for (const auto& e : pFitters) {
		std::cout << "Derived Polynomial is: " << Parser::parseToPolynomialString(e->getPolynomial()->getCoefficients()) << '\n';
		std::cout << "Input Set Range: {" << Parser::parseToCsvString(e->getInputSetRange()) << "}\n";
		std::cout << "-----------------------------------------------------------------" << '\n';
	}
}

void FittingSimulationHandler::writeOutputToFile() {
	std::cout << "Filename (REQUIRED '.txt'): ";
	std::string filename = handleUserInput(false);

	std::vector<FileHandler::FileFormatEXP> output;
	for (const auto& e : pFitters) {
		FileHandler::FileFormatEXP data(e->getPolynomial()->getCoefficients(), e->getInputSetRange());
		output.push_back(data);
	}
	FileHandler::TXT::write(filename, output);
	std::cout << "-----------------------------------------------------------------" << '\n';
	std::cout << "Your output has been written to " << filename << '\n';
	std::cout << "-----------------------------------------------------------------" << '\n';
}
