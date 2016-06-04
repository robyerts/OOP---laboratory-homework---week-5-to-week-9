#pragma once
#include "Repository.h"
#include "WatchListCSV.h"
#include "WatchListHTML.h"
#include <algorithm> 


class ControllerUser
{
private:
	Repository * repo;
	std::vector<Tutorial> filtered;
	int pos;
	WatchList * watchL;



public:
	ControllerUser(Repository *r, WatchList *w) : repo(r), watchL(w),pos(0) {}
	//this function fils the dynamic vector by given presenter
	int filter(std::string presenter);
	// returns the current tutorial from dynamic vector filtered
	Tutorial getCurrent();
	//increments the dynamic vector iterator
	void next();
	//adds a tutorial to the watchList
	void addTutorial(Tutorial t);
	//deletes a tutorial from the the watchlist, based on given artist and title
	//returns 1 if compelted
	//-1 if failed
	int deleteTutorial(std::string artist, std::string title);
	//updates a Tutorial in the ADMINISTRATOR REPOSITORY
	void update(Tutorial t);
	std::string toString();
	void DisplayFile();

	int ControllerUser::watchTheList();




};