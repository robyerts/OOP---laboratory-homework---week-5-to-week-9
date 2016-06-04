#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;

public:
	UI( Controller& c) : ctrl(c) {}

	void run();

private:
	static void printRepositoryMenu();
	
	void addTutorialToRepo();
	void displayAllTutorialsRepo();
	void DeleteTutorial();

	void update();

};


