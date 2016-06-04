#pragma once
#include"WatchListFile.h"
#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
#include <sstream>

class WatchListCSV :public WatchListFile
{
public:
	void DisplayFile();
	void writeTutorials();

};
