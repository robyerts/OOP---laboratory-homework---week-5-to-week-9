#include "UI.h"
#include <string.h>
#include <iostream>

using namespace std;



void UI::printRepositoryMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add Tutorial." << endl;
	cout << "\t 2 - Display all." << endl;
	cout << "\t 3 - Delete by presenter and name" << endl;
	cout << "\t 4 - update an item." << endl;
	cout << "\t 0 - Back." << endl;
}

//void UI::printUpdateMenu()
//{
//	cout << "Possible commands: " << endl;
//	cout << "\t 1 - set source" << endl;
//	cout << "\t 2 - set duration" << endl;
//	cout << "\t 3 - set likes" << endl;
//	cout << "\t 0 - Back." << endl;
//}

void UI::update()
{
	cout << "Enter the presenter: ";
	std::string artist;
	getline(cin,artist);
	while (artist.size() < 3)
	{
		cout << "error" << endl;
		getline(cin, artist);
	}
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	while (title.size() < 3)
	{
		cout << "error" << endl;
		getline(cin, artist);
	}
	/*this->printUpdateMenu();
	int opt;
	cin >> opt;
	cin.ignore();*/


	int minutes = 0, seconds = 0;
	cout << "Enter the duration: " << endl;
	cout << "\tMinutes: ";
	cin >> minutes;
	while (cin.fail()) {
		cout << "Error" << std::endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> minutes;
	}
	cin.ignore();
	cout << "\tSeconds: ";
	cin >> seconds;
	while (cin.fail()) {
		cout << "Error" << std::endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> seconds;
	}
	cin.ignore();
	cout << "Youtube link: ";
	std::string link;
	getline(cin, link);
	int likes;
	cout << "enter the number of likes: ";
	cin >> likes;
	while (cin.fail()) {
		cout << "Error" << std::endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> likes;
	}
	cin.ignore();
	try {
		this->ctrl.update(artist, title, minutes, seconds, link, likes);
	}
	catch (ValidationException& ex)
	{
		cout << ex.getMessage() << endl;
	}
	
	
}

void UI::addTutorialToRepo()
{
	cout << "Enter the presenter: ";
	std::string artist;
	getline(cin, artist);;
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	int minutes = 0, seconds = 0;
	cout << "Enter the duration: " << endl;
	cout << "\tMinutes: ";
	cin >> minutes;
	while (cin.fail()) {
		cout << "Error" << std::endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> minutes;
	}
	cin.ignore();
	cout << "\tSeconds: ";
	cin >> seconds;
	while (cin.fail()) {
		cout << "Error" << std::endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> seconds;
	}
	cin.ignore();
	cout << "Youtube link: ";
	std::string link;
	getline(cin, link);
	int likes;
	cout << "enter the number of likes: ";
	cin >> likes;
	while (cin.fail()) {
		cout << "Error" << std::endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> likes;
	}
	cin.ignore();
	try
	{
		this->ctrl.addTutorialToRepository(artist, title, minutes, seconds, link, likes);
	}
	catch (ValidationException& ex)
	{
		cout << ex.getMessage() << endl;
	}
}
void UI::DeleteTutorial()
{
	cout << "Enter the presenter: ";
	std::string artist;
	getline(cin, artist);
	while (artist.size() < 3)
	{
		cout << "error" << endl;
		getline(cin, artist);
	}
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	while (title.size() < 3)
	{
		cout << "error" << endl;
		getline(cin, artist);
	}
	this->ctrl.deleteTutorial_ctrl(artist, title);
}



void UI::displayAllTutorialsRepo()
{
	cout << this->ctrl.toString_ctrl();
}


void UI::run()
{
	
			while (true)
			{
				UI::printRepositoryMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				while (cin.fail()) {
					cout << "Error" << std::endl;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> commandRepo;
				}
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->addTutorialToRepo();
					break;
				case 2:
					this->displayAllTutorialsRepo();
					break;
				case 3:
					this->DeleteTutorial();
					break;
				case 4:
					this->update();
					break;
				}
			}
		
	
		
}