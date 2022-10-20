#include "FittingSimulationHandler.h"
#include "Parser.h"
#include "FileHandler.h"


void FittingSimulationHandler::getInputFromConsole() {
	std::cout << "Please enter your inputs, type 'UNKNOWN' if you do not know it: " << "\n\t";

	std::cout << "Enter output set: "; //DONT ACCEPT UNKNOWN HERE
	std::vector<int> coeff = Parser::parseCSV(handleUserInput(false));

	std::cout << "Enter start number of the input range: ";
	//HANLDE INVALID INPUT AND UNKNOWNNNNN
	int num1 = std::stoi(handleUserInput(false));

	std::cout << "Enter finish number of the input range: ";
	int num2 = std::stoi(handleUserInput(false));

	std::cout << "Enter number of terms in the polynomial: ";
	std::string num = handleUserInput(false);
	int numTerms{ 0 };
	if (num != "UNKNOWN") numTerms = std::stoi(handleUserInput(false));

	numTerms ? pFitters.push_back(new PolynomialFitter(coeff, num1, num2, numTerms)) : pFitters.push_back(new PolynomialFitter(coeff, num1, num2));
}

void FittingSimulationHandler::run() {
	for (const auto& fitter : pFitters) {
		fitter->fit();
	}
}

FittingSimulationHandler::~FittingSimulationHandler() {
	std::cout << "Destructing Fitting Simulation Handler\n";
	for (const auto& i : pFitters) {
		delete i;
	}
}

void FittingSimulationHandler::getInputFromFile() {
	std::cout << "Filename: ";
	std::string filename = handleUserInput(false);
	std::vector<FileHandler::FileFormatCSV> data = FileHandler::CSV::read(filename);

	for (const auto& e : data) {
		pFitters.push_back(new PolynomialFitter(e.outputSet, e.inputRange[0], e.inputRange[1], e.numTerms)); //?????????????????????????
	}
}

void FittingSimulationHandler::viewOutputOnConsole() {
	std::cout << "-----------------------------------------------------------------" << '\n';
	//std::cout << "Derived Polynomial is: " << Parser::parseToPolynomialString(pFitters[0]->getPolynomial()) << '\n';
	std::cout << "-----------------------------------------------------------------" << '\n';
}

void FittingSimulationHandler::writeOutputToFile() {
	std::cout << "Filename: ";
	std::string filename = handleUserInput(false);

	std::vector<std::vector<int>> output;
	for (const auto& e : pFitters) {
		//output.push_back(e->getOutput());
	}
	FileHandler::CSV::write(filename, output);
	std::cout << "-----------------------------------------------------------------" << '\n';
	std::cout << "Your output has been written to " << filename << '\n';
	std::cout << "-----------------------------------------------------------------" << '\n';
}
