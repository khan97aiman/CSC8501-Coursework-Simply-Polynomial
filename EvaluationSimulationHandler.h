#pragma once
#include "BaseSimulationHandler.h"
#include "PolynomialEvaluator.h"
class EvaluationSimulationHandler : public BaseSimulationHandler {
	std::vector<PolynomialEvaluator*> evaluators; //change to pEvaluators;
public:
	virtual void getInput();
	virtual void run();
	virtual void handleFileInput();
	virtual void viewOutputOnConsole();
	virtual void viewOutputOnFile();	
	virtual ~EvaluationSimulationHandler() {
		//delete evaluators
		std::cout << "Destructing Evaluation Simulation Handler\n";
		for (const auto& i : evaluators) {
			delete i;
		}

	}
};

