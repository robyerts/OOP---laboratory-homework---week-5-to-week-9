#include "Tutorial.h"
#include <Windows.h>
#include <shellapi.h>
#include <stdio.h>
#include <assert.h>


using namespace std;

Tutorial::Tutorial()
{
	this->artist = "";
	this->title = "";
	this->duration = Duration();
	this->source="";
	this->likes = 0;
}

Tutorial::Tutorial(std::string title, std::string artist, Duration duration, std::string source, int likes)

{
	this->artist = artist;
	this->title = title;
	this->duration = duration;
	this->source = source;
	this->likes = likes;
}

std::string Tutorial::getTitle() 
{
	return this->title;
}

std::string Tutorial::getArtist()
{
	return this->artist;
}

std::string Tutorial::getSource()
{
	return this->source;
}

void Tutorial::setTitle(std::string title)
{
	this->title=title;
}

void Tutorial::setArtist(std::string artist)
{
	this->artist=artist;
}

void Tutorial::setSource(std::string strr)
{
	this->source=strr;
}
void Tutorial::setDuration(Duration t)
{
	this->duration = t;
}
void Tutorial::setLikes(int number)
{
	this->likes = number;
}

std::string Tutorial::toString()
{
	return this->getTitle() + " | " + this->getArtist() + " | " + std::to_string(this->getDuration().getMinutes())+":"+ std::to_string(this->getDuration().getSeconds())   + " | " + this->getSource() + " | " + std::to_string(this->getLikes())+" likes"+"\n";
}

void Tutorial::play()
{

	ShellExecuteA(NULL, NULL, "chrome.exe", this->source.c_str(), NULL, SW_SHOWMAXIMIZED);
}
///////overload of the = not needed
//Tutorial & Tutorial::operator=(const Tutorial& other) {
	/*this->artist = other.artist;
	this->title = other.title;
	this->duration = other.duration;
	this->source = other.source;
	this->likes = other.likes;*/
//	return *this;
//}

bool Tutorial::operator==(const Tutorial& other) {
	return (
		this->artist == other.artist&&
		this->title == other.title);
		//this->duration.getMinutes() == other.duration.getMinutes() &&
		//this->duration.getSeconds() == other.duration.getSeconds() &&
		//this->source == other.source&&
		//this->likes == other.likes);
}
bool Tutorial::operator!=(const Tutorial& other) {
	return !(*this == other);
}

void tests()
{
	Duration d1 = Duration(5, 55);
	Duration d2 = Duration(0, 20);
	Tutorial t1 = Tutorial("Introduction to shell", "Rares Boian", d1, "http://na.leagueoflegends.com/en/news/game-updates/patch/patch-66-notes", 123);
	Tutorial t11 = Tutorial("Introduction to shell", "Rares Boian", d1, "http://na.leagueoflegends.com/en/news/game-updates/patch/patch-66-notes", 123);
	assert(t1==t11);
	Tutorial t2 = Tutorial("c++ for dummies", "Rares Boian", d2, "https://www.youtube.com/watch?v=kmnC6IUPGjI&list=PLZlv_N0_O1gaCL2XjKluO7N2Pmmw9pvhE&index=42", 222);
	assert(t1 != t2);
}

vector<string> tokenize(string str, char delimiter)
{
	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}

std::istream & operator>>(std::istream & is, Tutorial & s)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 6) // make sure all the starship data was valid
		return is;
	s.title = tokens[0];
	s.artist = tokens[1];
	s.duration.setMinutes(stoi(tokens[2]));
	s.duration.setSeconds(stoi(tokens[3]));
	s.source = tokens[4];
	s.likes = stoi(tokens[5]);

	return is;
}

std::ostream & operator<<(std::ostream & os,  Tutorial & s)
{
	os << s.title << "," << s.artist << "," << s.duration.getMinutes() << "," << s.duration.getSeconds() << "," << s.source << "," << s.likes<< "\n";
	return os;
}

//int main()
//{
//	tests();
//	return 0;
//}