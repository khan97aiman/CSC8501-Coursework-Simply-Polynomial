#include "SimplyPolynomialSimulator.h"
#include <iostream>

void SimplyPolynomialSimulator::startUp() {
    std::cout << "***************************************" << '\n';
    std::cout << "Welcome to Simply Polynomial Simulator!" << '\n';
    std::cout << "***************************************" << "\n\n";

    std::cout << "Press 'Q' to exit this simulation, otherwise have fun using it :)" << '\n';
    std::cout << "=================================================================" << '\n';
}

void SimplyPolynomialSimulator::mainMenu() { //make these functions part of constructor????
    std::cout << "-----------------------------------" << '\n';
    std::cout << "Please select one of the following:" << "\n\t";
    std::cout << "Press 1 to view output set given an algebraic expression" << "\n\t";
    std::cout << "Press 2 to derive an algebraic expression given an output set" << '\n';
    std::cout << "Waiting for your input: ";
    std::string input;
    std::cin >> input;
    if (input == "1") simulationHandler = new EvaluationSimulationHandler();
    //else if (input == "2") simulationHandler = n
    else {
        std::cout << "Invalid Command!" << '\n';
        mainMenu();
    }
}

void SimplyPolynomialSimulator::run() {
    simulationHandler->getInputMethod();
    simulationHandler->run();
    simulationHandler->viewOutputMethod(); //change name to get output method
}
