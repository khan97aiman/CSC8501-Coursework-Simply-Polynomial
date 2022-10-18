#pragma once
#include <iostream>
class BaseSimulationHandler {
public:
	std::string handleUserInput();
	void getInputMethod();
	//virtual void getFilenameForInput() = 0;
	void getFilenameForOutput(); //also pure vvirtual
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

