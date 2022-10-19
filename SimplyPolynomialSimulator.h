#pragma once
#include <cstddef>
#include "BaseSimulationHandler.h"
#include "EvaluationSimulationHandler.h"

//enum class simulator state? running ended?
class SimplyPolynomialSimulator {
	BaseSimulationHandler* simulationHandler; //you might need to delete before destructor called??
public:
	void startUp();
	void mainMenu();
	void run();
	~SimplyPolynomialSimulator();
};

