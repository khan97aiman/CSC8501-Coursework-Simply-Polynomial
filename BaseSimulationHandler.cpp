#include "BaseSimulationHandler.h"

void BaseSimulationHandler::getInputMethod() {
	std::cout << "Please select your input method:" << "\n\t";
	std::cout << "Press '1' to input via console" << "\n\t";
	std::cout << "Press '2' to input via a file" << '\n';

	std::string input = handleUserInput();
	if (input == "1") getInputFromConsole();
	else if (input == "2") getInputFromFile();
	else {
		handleInvalidInput();
		getInputMethod();
	}
}

void BaseSimulationHandler::getOutputMethod() {
	std::cout << "Please select how you want to view your output:" << "\n\t";
	std::cout << "Press '1' to view output on console" << "\n\t";
	std::cout << "Press '2' to write output to file" << "\n";

	std::string input = handleUserInput();
	if (input == "1") viewOutputOnConsole();
	else if (input == "2") writeOutputToFile();
	else {
		handleInvalidInput();
		getOutputMethod();
	}
}
