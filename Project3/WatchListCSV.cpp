#include <Windows.h>
#include <shellapi.h>
#include <stdio.h>
#include <assert.h>
#include "WatchListCSV.h"

using namespace std;

void WatchListCSV::writeTutorials()
{
	
		ofstream f("WatchList.csv");	// NO append data
		if (!f.is_open())
			return;


		for (auto s : Tutorials)
		{
			f << s;
		}

		f.close();
}

void WatchListCSV::DisplayFile()
{

	ShellExecuteA(NULL, NULL, "notepad.exe", "WatchList.csv", NULL, SW_SHOWMAXIMIZED);
}