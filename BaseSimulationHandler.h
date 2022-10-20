#pragma once
#include <iostream>
#include "HelperFunctions.h"
class BaseSimulationHandler {
protected:
	virtual void getInputFromConsole() = 0;
	virtual void getInputFromFile() = 0;
	virtual void viewOutputOnConsole() = 0;
	virtual void writeOutputToFile() = 0;

public:
	void getInputMethod();
	void getOutputMethod();
	virtual void run() = 0;
	virtual ~BaseSimulationHandler() {};
};

