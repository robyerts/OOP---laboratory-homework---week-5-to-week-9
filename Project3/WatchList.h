#pragma once
#include "Tutorial.h"
#include <vector>

class WatchList
{
protected:
	std::vector<Tutorial> Tutorials;

public:

	//ads a tutorial to the watchList
	virtual void addTutorial(Tutorial s);

	//// returns the position of the tutorial in the watchList having a given presenter and name or -1 if it can find it
	//int findByArtistAndTitle(std::string artist, std::string name);

	//deletes a tutorial from the watchList having a given presenter and title
	//returns 1 if compelted
	//-1 if failed
	virtual int DeleteTutorial(std::string artist, std::string title);
	std::vector<Tutorial> getAll();
	std::string WatchList::toString();
	virtual void WatchList::DisplayFile() = 0;
	

};