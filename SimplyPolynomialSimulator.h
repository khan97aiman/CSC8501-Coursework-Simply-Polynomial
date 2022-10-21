#pragma once
#include <cstddef>
#include "BaseSimulationHandler.h"
#include "EvaluationSimulationHandler.h"

class SimplyPolynomialSimulator {
	BaseSimulationHandler* simulationHandler; 
public:
	void startUp();
	void mainMenu();
	void run();
	~SimplyPolynomialSimulator();
};

