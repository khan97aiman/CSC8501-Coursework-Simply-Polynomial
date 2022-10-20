#include "SimplyPolynomialSimulator.h"
#include <iostream>
#include "HelperFunctions.h"

void SimplyPolynomialSimulator::startUp() {
    std::cout << "*****************************************************************" << '\n';
    std::cout << "             Welcome to Simply Polynomial Simulator!             " << '\n';
    std::cout << "*****************************************************************" << "\n\n";

    std::cout << "Press 'Q' to exit this simulation, otherwise have fun using it :)" << '\n';
    std::cout << "=================================================================" << '\n';
}

void SimplyPolynomialSimulator::mainMenu() { 
    std::cout << "Please select one of the following:" << "\n\t";
    std::cout << "Press 1 to view output set given an algebraic expression" << "\n\t";
    std::cout << "Press 2 to derive an algebraic expression given an output set" << '\n';
    
    std::string input { handleUserInput() };
    if (input == "1") simulationHandler = new EvaluationSimulationHandler();
    else {
        handleInvalidInput();
        mainMenu();
    }
}

void SimplyPolynomialSimulator::run() {
    simulationHandler->getInputMethod();
    simulationHandler->run();
    simulationHandler->getOutputMethod();
}

SimplyPolynomialSimulator::~SimplyPolynomialSimulator() {
    delete simulationHandler;
}
