#include "WatchListFile.h"
#include <Windows.h>
#include <shellapi.h>
#include <stdio.h>
#include <assert.h>


using namespace std;



void WatchListFile::addTutorial(Tutorial s)
{
	auto it = find(Tutorials.begin(), Tutorials.end(), s);
	if (it == Tutorials.end())
	{
		this->Tutorials.push_back(s);
		this->writeTutorials();
	}

}

int	WatchListFile::DeleteTutorial(std::string artist, std::string title)
{
	
		Tutorial s = Tutorial();
		s.setArtist(artist);
		s.setTitle(title);
		auto it = find(Tutorials.begin(), Tutorials.end(), s);
		if (it != Tutorials.end())
		{
			this->Tutorials.erase(it);
			this->writeTutorials();
			return 1;
		}
		return -1;
	
}
