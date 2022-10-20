#pragma once
#include "BaseSimulationHandler.h"
#include "PolynomialEvaluator.h"

class EvaluationSimulationHandler : public BaseSimulationHandler {
	std::vector<PolynomialEvaluator*> pEvaluators;
	
	virtual void getInputFromConsole();
	virtual void getInputFromFile();
	virtual void viewOutputOnConsole();
	virtual void writeOutputToFile();	

public:
	virtual void run();
	virtual ~EvaluationSimulationHandler();
};

