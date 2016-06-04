#include "Repository.h"
#include <string.h>
#include <sstream>
#include <fstream>


using namespace std;

Repository::Repository()
{
	this->readTutorials();
}

void Repository::addTutorial2(Tutorial s)
{
	
		TutorialValidator v;
		v.validate(s);
		auto it = find(Tutorials.begin(), Tutorials.end(), s);
		if (it == Tutorials.end())
			this->Tutorials.push_back(s);
	
}

void Repository::addTutorial( Tutorial s)
{
	
		TutorialValidator v;
		v.validate(s);
		auto it = find(Tutorials.begin(), Tutorials.end(), s);
		if (it == Tutorials.end())
		{
			this->Tutorials.push_back(s);
			this->writeTutorials();
		}
	
	/*catch (ValidationException& ex)
	{
		cout << ex.getMessage() << endl;
	}*/
	
}

void Repository::replace( Tutorial s)
{
	TutorialValidator v;
	v.validate(s);
	auto it = find(Tutorials.begin(), Tutorials.end(), s);
	if (it != Tutorials.end())
	{
		*it = s;
		this->writeTutorials();
	}
	
}



void Repository::DeleteTutorial(std::string artist, std::string title)
{
	
	Tutorial s = Tutorial();
	s.setArtist(artist);
	s.setTitle(title);
	auto it = find(Tutorials.begin(), Tutorials.end(), s);
	if (it != Tutorials.end())
	
		this->Tutorials.erase(it);
	this->writeTutorials();
}


std::string Repository::toString_repo()
{
	std::string buffer;
	for (std::vector<Tutorial>::iterator it = Tutorials.begin(); it != Tutorials.end(); it++)
		buffer =buffer+ (*it).toString();
	return buffer;
	
}

std::vector<Tutorial> Repository::getAll()
{
	return this->Tutorials;
}


void Repository::readTutorials()
{
	ifstream f("Tutorials.csv");
	if (!f.is_open())
		return;
	Tutorial s{};
	while (f >> s)
	{
		this->addTutorial2(s);
	}
	

	f.close();
}

void Repository::writeTutorials()
{
	ofstream f("Tutorials.csv");	// NO append data
	if (!f.is_open())
		return;


	for (auto s : Tutorials)
	{
		f << s;
	}

	f.close();
}
void tests_repo()
{
	/*Duration dd1 = Duration(4, 55);
	Duration dd2 = Duration(0, 10);
	Duration dd3 = Duration(1, 2);
	Tutorial tt1 = Tutorial("Introduction to shell", "Rares boian", dd1, "http://na.leagueoflegends.com/en/news/game-updates/patch/patch-66-notes", 123);
	Tutorial tt2 = Tutorial("c++ for dummies", "Rares boian", dd2, "https://www.youtube.com/watch?v=kmnC6IUPGjI&list=PLZlv_N0_O1gaCL2XjKluO7N2Pmmw9pvhE&index=42", 223);
	Tutorial tt3 = Tutorial("Virtual Functions", "Iuliana Bocicor", dd3, ",https://www.youtube.com/watch?v=jiwuQ6UHMQg", 99);*/
	Repository repo;
	/*assert(repo.toString_repo() == (tt1.toString() + tt2.toString() + tt3.toString()));*/
	/*repo.addTutorial2(tt1);
	repo.addTutorial2(tt2);*/
	
}