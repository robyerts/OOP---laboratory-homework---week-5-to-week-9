#pragma once
#include "ControllerUser.h"
class UI_User
{
private:
	ControllerUser ctrlU;

public:
	UI_User(ControllerUser& c) : ctrlU(c) {}

	void run();

private:
	void printUserMenu();
	void printIterateMenu();
	void iterate();

	void UI_User::iterateWatch();

};