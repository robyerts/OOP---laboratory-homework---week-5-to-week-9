#include "WatchList.h"
#include <string.h>
#include <fstream>

void WatchList::addTutorial(Tutorial s)
{
	auto it = find(Tutorials.begin(), Tutorials.end(), s);
	if (it == Tutorials.end())
		this->Tutorials.push_back(s);
}


//int WatchList::findByArtistAndTitle(std::string artist, std::string title)
//{
//
//	for (int i = 0; i < this->Tutorials.getSize(); i++)
//	{
//		Tutorial s = this->Tutorials[i];
//		if (s.getArtist() == artist && s.getTitle() == title)
//			return i;
//	}
//	return -1;
//
//}

int WatchList::DeleteTutorial(std::string artist, std::string title)
{
	Tutorial s = Tutorial();
	s.setArtist(artist);
	s.setTitle(title);
	auto it = find(Tutorials.begin(), Tutorials.end(), s);
	if (it != Tutorials.end())
	{
		this->Tutorials.erase(it);
		return 1;
	}
	return -1;
}


std::string WatchList::toString()
{
	std::string buffer;
	for (std::vector<Tutorial>::iterator it = Tutorials.begin(); it != Tutorials.end(); it++)
		buffer = buffer + (*it).toString();
	return buffer;
}

std::vector<Tutorial> WatchList::getAll()
{
	return this->Tutorials;
}