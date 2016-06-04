#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Duration
{
private:
	int minutes;
	int seconds;
public:
	Duration() : minutes(0), seconds(0) {}
	Duration(int min, int sec) : minutes(min), seconds(sec) {}

	int getMinutes() { return minutes; }
	int getSeconds() { return seconds; }
	void setMinutes(int min) { minutes = min; }
	void setSeconds(int sec) { seconds = sec; }
};

class Tutorial
{
private:
	std::string title;
	std::string artist;
	Duration duration;
	std::string source;		// youtube Link
	int likes;

public:
	// default constructor for a Tutorial
	Tutorial();


	// constructor with parameters
	Tutorial(std::string title, std::string artist, Duration duration, std::string source,int likes);

	// getters and setters

	std::string getTitle() ;
	void setTitle(std::string title);
	std::string getArtist()  ;
	void setArtist(std::string artist);
	Duration getDuration() { return duration; }
	void setDuration(Duration t);
	std::string getSource() ;
	void setSource(std::string strr);
	int getLikes() { return likes; }
	void setLikes(int number);

	/*Tutorial & operator=(const Tutorial& other);*/

	bool operator==(const Tutorial& other);
	bool operator!=(const Tutorial& other);

	friend std::istream& operator>>(std::istream& is, Tutorial & s);
	friend std::ostream& operator<<(std::ostream& os,  Tutorial& s);

	std::string toString();

	// Plays the current Tutorial: the page corresponding to the source link is opened in a browser.
	void play();
};

void tests();

