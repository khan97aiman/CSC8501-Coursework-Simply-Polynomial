#include "SimplyPolynomialSimulator.h"
#include <iostream>
#include "HelperFunctions.h"
#include "FittingSimulationHandler.h"

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
    else if (input == "2") simulationHandler = new FittingSimulationHandler();
    else {
        handleInvalidInput();
        mainMenu();
    }
}

void SimplyPolynomialSimulator::run() {
    try {
        simulationHandler->getInputMethod();
        simulationHandler->run();
        simulationHandler->getOutputMethod();
    }
    catch (const std::exception& e) {
        handleException(e);
    }
}

SimplyPolynomialSimulator::~SimplyPolynomialSimulator() {
    delete simulationHandler;
}
