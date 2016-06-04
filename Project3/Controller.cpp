#include "Controller.h"
#include <string.h>
#include <iostream>

using namespace std;

void Controller::addTutorialToRepository(std::string artist, std::string title, int minutes, int seconds, std::string source, int likes)
{
	Tutorial s{ title ,artist, Duration{ minutes, seconds }, source,likes };
	this->repo->addTutorial(s);
}

std::string Controller::toString_ctrl()
{
	return this->repo->toString_repo();
}

//Repository Controller::toString_filter(std::string presenter)
//{
//	Repository repo2 = this->repo;
//	repo2.filter(presenter);
//	return repo2;
//}

void Controller::deleteTutorial_ctrl(std::string artist, std::string title)
{
	this->repo->DeleteTutorial(artist, title);
}



void Controller::update(std::string artist, std::string title, int minutes, int seconds, std::string source, int likes)
{
	Tutorial s{ title,artist, Duration{ minutes, seconds }, source,likes };
	this->repo->replace(s);
}





