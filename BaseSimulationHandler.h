#pragma once
#include <iostream>
class BaseSimulationHandler {
public:
	std::string handleUserInput();
	void getInputMethod();
	void getFilenameForInput();
	void getFilenameForOutput();
	void viewOutputMethod();
	
	virtual void getInput() = 0;
	virtual void run() = 0;
	virtual void handleFileInput() = 0;
	virtual void viewOutputOnConsole() = 0;
	virtual void viewOutputOnFile() = 0;

	virtual ~BaseSimulationHandler() {
		std::cout << "Destructing base simulation handler\n";
	}

};

