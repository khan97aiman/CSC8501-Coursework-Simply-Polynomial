#include "BaseSimulationHandler.h"

std::string BaseSimulationHandler::handleUserInput() {
	std::cout << "Waiting for your input: ";
	std::string input;
	std::cin >> input;
	return input;
}

void BaseSimulationHandler::getInputMethod() {
	std::cout << "--------------------------------" << '\n';
	std::cout << "Please select your input method:" << "\n\t";
	std::cout << "Press '1' to input via console" << "\n\t";
	std::cout << "Press '2' to input via a file" << '\n';

	std::string input = handleUserInput();
	if (input == "1") getInput();
	else if (input == "2") getFilenameForInput();
	else {
		std::cout << "Invalid Command!" << '\n';
		getInputMethod();
	}
}

void BaseSimulationHandler::getFilenameForInput() {
	std::cout << "Please enter the name of the file you want to read from" << "\n";
	std::string input = handleUserInput();
	
}

void BaseSimulationHandler::getFilenameForOutput() {
	std::cout << "Please enter the name of the file to want to write to" << "\n";
}

void BaseSimulationHandler::viewOutputMethod() {
	std::cout << "--------------------------------" << '\n';
	std::cout << "Please select how you want to view your output:" << "\n\t";
	std::cout << "Press '1' to view output on console" << "\n\t";
	std::cout << "Press '2' to view output on file" << "\n";
	//std::cout << "Press '3' to view output on graph" << "\n";

	std::string input = handleUserInput();
	if (input == "1") viewOutputOnConsole();
	else if (input == "2") viewOutputOnFile();
	else {
		std::cout << "Invalid Command!" << '\n';
		viewOutputMethod();
	}
}
