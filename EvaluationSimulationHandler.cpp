#include "EvaluationSimulationHandler.h"
#include "Parser.h"
#include "FileHandler.h"

void EvaluationSimulationHandler::getInputFromConsole() {
	std::cout << "Please enter your inputs" << "\n\t";

	std::cout << "Enter polynomial: ";
	std::vector<int> coeff = Parser::parsePolynomial(handleUserInput(false));

	std::cout << "Enter start number of the input range: ";
	int num1 = std::stoi(handleUserInput(false));

	std::cout << "Enter finish number of the input range: ";
	int num2 = std::stoi(handleUserInput(false));

	//RESERVE BEFORE PUSH BACK???
	pEvaluators.push_back(new PolynomialEvaluator(coeff, num1, num2));
}

void EvaluationSimulationHandler::run() {
	for (const auto& evaluator : pEvaluators) {
		evaluator->evaluate();
	}
}

EvaluationSimulationHandler::~EvaluationSimulationHandler() {
	std::cout << "Destructing Evaluation Simulation Handler\n";
	for (const auto& i : pEvaluators) {
		delete i;
	}
}

void EvaluationSimulationHandler::getInputFromFile() {
	std::cout << "Filename: ";
	std::string filename = handleUserInput(false);
	std::vector<FileHandler::FileFormatEXP> data = FileHandler::TXT::readBulk(filename);

	for (const auto& e : data) {
		pEvaluators.push_back(new PolynomialEvaluator(e.pCoefficients, e.inputRange[0], e.inputRange[1]));
	}
}

void EvaluationSimulationHandler::viewOutputOnConsole() {
	std::cout << "-----------------------------------------------------------------" << '\n';
	std::cout << "Output Set: {" << Parser::parseToCsvString(pEvaluators[0]->getOutput()) << "}\n";
	std::cout << "-----------------------------------------------------------------" << '\n';
}
void EvaluationSimulationHandler::writeOutputToFile() {
	std::cout << "Filename: ";
	std::string filename = handleUserInput(false);

	std::vector<std::vector<int>> output;
	for (const auto& e : pEvaluators) {
		output.push_back(e->getOutput());
	}
	FileHandler::CSV::writeBulk(filename, output);
	std::cout << "-----------------------------------------------------------------" << '\n';
	std::cout << "Your output has been written to " << filename << '\n';
	std::cout << "-----------------------------------------------------------------" << '\n';
}
