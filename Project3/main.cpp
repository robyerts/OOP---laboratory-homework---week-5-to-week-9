#include "UI.h"
#include "UI_User.h"
#include <Windows.h>

using namespace std;
void printMenu()
{
	cout << endl;
	cout << "1 - Administrator mode" << endl;
	cout << "2 - User mode." << endl;
	cout << "0 - Exit." << endl;
}

int main()
{
	Duration d1 = Duration(4, 55);
	Duration d2 = Duration(0, 10);
	Duration d3 = Duration(1, 2);
	Tutorial t1 = Tutorial("Introduction to shell", "Rares Boian", d1, "http://na.leagueoflegends.com/en/news/game-updates/patch/patch-66-notes", 123);
	Tutorial t2 = Tutorial("c++ for dummies", "Rares Boian", d2, "https://www.youtube.com/watch?v=kmnC6IUPGjI&list=PLZlv_N0_O1gaCL2XjKluO7N2Pmmw9pvhE&index=42", 223);
	Tutorial t3 = Tutorial("Virtual Functions", "Iuliana Bocicor", d3, "https://www.youtube.com/watch?v=jiwuQ6UHMQg", 99);
	Repository repo=Repository();
	tests();   //tutorial tests
	//repo.addTutorial(t1);
	//repo.addTutorial(t2);
	//repo.addTutorial(t3);
	tests_repo();
	
	while (true)
	{
		printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		while (cin.fail()) {
			cout << "Error" << std::endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> command;
		}
		cin.ignore();
		if (command == 0)
			break;
		if (command == 1) {
			Controller ctrl(&repo);
			UI ui(ctrl);
			ui.run();
		}
		else if (command == 2) {
			cout << "STORAGE METHOD: " << endl;
			cout << "\t 1 - WatchList.csv" << endl;
			cout << "\t 2 - watchList.html" << endl;
			int writeOPT;
			cin >> writeOPT;
			while (cin.fail()) {
				cout << "Error" << std::endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> writeOPT;
			}
			WatchListFile *w;
			if (writeOPT==1)w=new WatchListCSV();
			else w=new WatchListHTML();
			ControllerUser ctrlUser(&repo, w);
			UI_User ui(ctrlUser);
			ui.run();
			delete w;
		}
	}
	return 0;
}