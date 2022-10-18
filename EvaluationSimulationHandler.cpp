#include "EvaluationSimulationHandler.h"
#include "Parser.h"

void EvaluationSimulationHandler::getInput() {
	std::cout << "Please enter your inputs" << "\n\t";

	std::cout << "Enter polynomial: " << "\n\t";
	//check if polynomial is correct????
	std::vector<int> coeff = Parser::parsePolynomial(handleUserInput());

	std::cout << "Enter start number of the input range: " << "\n\t";
	//check for invalid input????
	int num1 = std::stoi(handleUserInput());

	std::cout << "Enter finish number of the input range: " << "\n\t";
	int num2 = std::stoi(handleUserInput());

	//RESERVE BEFORE PUSH BACK
	evaluators.push_back(new PolynomialEvaluator(coeff, num1, num2));
}

void EvaluationSimulationHandler::run() {
	for (const auto& evaluator : evaluators) {
		evaluator->evaluate();
	}
}

void EvaluationSimulationHandler::handleFileInput() {
	std::cout << "Please enter the name of the file you want to read from" << "\n";
	std::string input = handleUserInput();

	
}

void EvaluationSimulationHandler::viewOutputOnConsole() {
	std::cout << Parser::parseToCSV(evaluators[0]->getOutput());
}
void EvaluationSimulationHandler::viewOutputOnFile() {
}
