#pragma once
#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
#include <sstream>
#include "WatchList.h"

class WatchListFile : public WatchList
{

public:
	void addTutorial(Tutorial s);
	int DeleteTutorial(std::string artist, std::string title);

	virtual void writeTutorials()=0;


};

