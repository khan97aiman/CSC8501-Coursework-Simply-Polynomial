#pragma once
#include <cstddef>
#include "BaseSimulationHandler.h"
#include "EvaluationSimulationHandler.h"

//enum class simulator state? running ended?
//enum class problem type == evaluation, fitting
//enum class input method == console, filename
//enum class output method == file, console, graph

class SimplyPolynomialSimulator {
	BaseSimulationHandler* simulationHandler; //you might need to delete before destructor called??
public:
	void startUp();
	void mainMenu();
	void run();
	~SimplyPolynomialSimulator() {
		std::cout << "Destructor for Simply Polynomial Simulator Called\n";
		delete simulationHandler;
	}

};

