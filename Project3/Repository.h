#pragma once
#include "Tutorial.h"
#include <assert.h>
#include <vector>
#include <iostream>
#include <fstream>
#include "TutorialValidator.h"

class Repository
{
private:
	std::vector<Tutorial> Tutorials;

public:

	Repository();
	/*
	Adds a Tutorial to the repository.
	Input: s - Tutorial.
	Output: the Tutorial is added to the repository.
	*/
	void addTutorial( Tutorial s);
	void addTutorial2(Tutorial s);

	
	/*
	deletes a tutorial by artist and title
	Input: artist, title - char array
	*/
	void DeleteTutorial(std::string artist, std::string title);
	
	
	std::string toString_repo();
	
	std::vector<Tutorial> getAll();

	void replace( Tutorial s);

	void readTutorials();
	void writeTutorials();



};

void tests_repo();
//{
//	Duration dd1 = Duration(5, 55);
//	Duration dd2 = Duration(0, 20);
//	Tutorial tt1 = Tutorial("Introduction to shell", "Rares boian", dd1, "http://na.leagueoflegends.com/en/news/game-updates/patch/patch-66-notes", 123);
//	Tutorial tt2 = Tutorial("c++ for dummies", "Rares boian", dd2, "https://www.youtube.com/watch?v=kmnC6IUPGjI&list=PLZlv_N0_O1gaCL2XjKluO7N2Pmmw9pvhE&index=42", 222);
//	Repository repo;
//	repo.addTutorial(tt1);
//	repo.addTutorial(tt2);
//	
//}