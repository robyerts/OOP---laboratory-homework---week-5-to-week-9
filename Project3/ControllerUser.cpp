#include "ControllerUser.h" 


int ControllerUser::filter(std::string presenter)
{
	/*this->filtered.resize(repo->getAll().size());
	copy_if(repo->getAll().begin(), repo->getAll().end(), filtered.begin(), [presenter](Tutorial s) {return (s.getArtist() == presenter); });*/
	
	//for (std::vector<Tutorial>::iterator it = filtered.begin(); it != filtered.end(); it++)
	//{
	//	Tutorial s = *it;
	//	if (s.getArtist() != presenter)
	//	{
	//		this->filtered.erase(it);
	//		//it--;
	//	}
	//}
	/*this->filtered = repo->getAll();
	for (Tutorial s : filtered)
	{
		if(s.getArtist()!=presenter)
			filtered.erase(std::remove(filtered.begin(), filtered.end(), s), filtered.end());
	}*/
	this->filtered = repo->getAll();
	filtered.erase(
		std::remove_if(filtered.begin(), filtered.end(),
			[presenter](Tutorial s) {return (s.getArtist() != presenter); }),
		filtered.end());
	if (filtered.empty())
		return -1;
	pos = 0;
	return 1;
}
int ControllerUser::watchTheList()
{
	if (!this->watchL->getAll().empty())
	{
		this->filtered = this->watchL->getAll();
		pos = 0;
		return 1;
	}
	return -1;
}

Tutorial ControllerUser::getCurrent()
{
	return filtered[pos];
	
}

void ControllerUser::next()
{
	pos++;
	if (filtered.size() == pos)
		pos = 0;
}
void ControllerUser::addTutorial(Tutorial t)
{
	this->watchL->addTutorial(t);
}

int ControllerUser::deleteTutorial(std::string artist, std::string title)
{
	return this->watchL->DeleteTutorial(artist, title);
}
void ControllerUser::update(Tutorial t)
{

	this->repo->replace(t);
}

std::string ControllerUser::toString()
{
	return this->watchL->toString();
}

void ControllerUser::DisplayFile()
{
	this->watchL->DisplayFile();
}

