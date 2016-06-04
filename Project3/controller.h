#pragma once
#include "Repository.h"


class Controller
{
private:
	Repository *repo;


public:
	Controller( Repository* r) : repo(r) {}


	// Adds a Tutorial with the given data to the Tutorial repository.
	void addTutorialToRepository( std::string artist, std::string title, int minutes, int seconds, std::string source, int likes);
	

	std::string toString_ctrl();

	//deletes a tutorial based on given artist and title
	//input:artist,title--strings
	void deleteTutorial_ctrl(std::string artist, std::string title);

	// update function for tutorials in the repository
	void update(std::string artist, std::string title, int minutes, int seconds, std::string source, int likes);

	//Repository Controller::toString_filter(std::string presenter);
	//void user_play()

};
