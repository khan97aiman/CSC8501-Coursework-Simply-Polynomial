#pragma once
#include "BaseSimulationHandler.h"
#include "PolynomialFitter.h"
class FittingSimulationHandler : public BaseSimulationHandler {
	std::vector<PolynomialFitter*> pFitters;

	virtual void getInputFromConsole();
	virtual void getInputFromFile();
	virtual void viewOutputOnConsole();
	virtual void writeOutputToFile();

public:
	virtual void run();
	virtual ~FittingSimulationHandler();
};

