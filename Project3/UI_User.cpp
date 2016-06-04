#include"UI_User.h"
#include <time.h>

using namespace std;

void UI_User::printUserMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Filter the database by presenter." << endl;
	cout << "\t 2 - Display watchlist." << endl;
	cout << "\t 3 - Play watchlist." << endl;
	cout << "\t 0 - Back." << endl;

}
void UI_User::printIterateMenu()
{
	cout << "possible commands: " << endl;
	cout << "\t 1 - add to watchlist " << endl;
	cout << "\t 2 - next" << endl;
	cout << "\t 0 - stop." << endl;

}
void UI_User::iterate()
{
	cout << "enter the presenter you wish to filter by"<<endl;
	string strr;
	getline(cin, strr);
	while (strr.size()<3) {
		cout << "Error" << std::endl;
		getline(cin, strr);
	}
	int res=this->ctrlU.filter(strr);

	while (res==1)
	{
		Tutorial t = this->ctrlU.getCurrent();
		cout << t.toString();
		t.play();
		time_t start = time(0);
		cout << "press anything in order to see the menu" << endl;
		string anuthing;
		getline(cin, anuthing);
		this->printIterateMenu();
		int flag = 0;
		if (difftime(time(0), start) > (t.getDuration().getMinutes() * 60 + t.getDuration().getSeconds()))
		{
			flag = 1;
			cout << "\t 3 - delete from watchlist  aaaand maybeee, like the tutorial :D" << endl;
		}
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
		if (commandRepo == 0 || (flag == 0 && commandRepo == 3))
			break;
		switch (commandRepo)
		{
		case 1:
			this->ctrlU.addTutorial(t);
			break;
		case 2:
			this->ctrlU.next();
			break;
		case 3:
		{
			int ans=this->ctrlU.deleteTutorial(t.getArtist(), t.getTitle());
			if (ans == -1)
				cout << "failed" << endl;
			else
			{
				cout << "did you liked the tutorial" << endl;
				cout << "\t 1 - yes" << endl;
				cout << "\t 2 - no" << endl;
				int commandRepo{ 0 };
				cout << "Input your answer: ";
				cin >> commandRepo;
				while (cin.fail()) {
					cout << "Error" << std::endl;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> commandRepo;
				}
				cin.ignore();
				if (commandRepo == 1)
				{
					t.setLikes(t.getLikes() + 1);
					this->ctrlU.update(t);
				}
			}
			break;

		}
		}
		if (commandRepo != 2)
		{
			cout << "possible commands: " << endl;
			cout << "\t 1 - next" << endl;
			cout << "\t 2 - stop" << endl;
			commandRepo = 0;
			cout << "Input the command: ";
			cin >> commandRepo;
			while (cin.fail()) {
				cout << "Error" << std::endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> commandRepo;
			}
			cin.ignore();
			if (commandRepo == 1)
				this->ctrlU.next();
			else
				break;
		}
	}
	}

void UI_User::iterateWatch()
{
	/*cout << "enter the presenter you wish to filter by" << endl;
	string strr;
	getline(cin, strr);*/
	int imp=this->ctrlU.watchTheList();
	while (imp==1)
	{
		Tutorial t = this->ctrlU.getCurrent();
		cout << t.toString();
		t.play();
		time_t start = time(0);
		cout << "press anything in order to see the menu" << endl;
		string anuthing;
		getline(cin, anuthing);
		this->printIterateMenu();
		int flag = 0;
		if (difftime(time(0), start) > (t.getDuration().getMinutes() * 60 + t.getDuration().getSeconds()))
		{
			flag = 1;
			cout << "\t 3 - delete from watchlist  aaaand maybeee, like the tutorial :D" << endl;
		}
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
		if (commandRepo == 0 || (flag == 0 && commandRepo == 3))
			break;
		switch (commandRepo)
		{
		case 1:
			this->ctrlU.addTutorial(t);
			break;
		case 2:
			this->ctrlU.next();
			break;
		case 3:
		{
			int ans = this->ctrlU.deleteTutorial(t.getArtist(), t.getTitle());
			if (ans == -1)
				cout << "failed" << endl;
			else
			{
				cout << "did you liked the tutorial" << endl;
				cout << "\t 1 - yes" << endl;
				cout << "\t 2 - no" << endl;
				int commandRepo{ 0 };
				cout << "Input your answer: ";
				cin >> commandRepo;
				while (cin.fail()) {
					cout << "Error" << std::endl;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> commandRepo;
				}
				cin.ignore();
				if (commandRepo == 1)
				{
					t.setLikes(t.getLikes() + 1);
					this->ctrlU.update(t);
				}
			}
			break;

		}
		}
		if (commandRepo != 2)
		{
			cout << "possible commands: " << endl;
			cout << "\t 1 - next" << endl;
			cout << "\t 2 - stop" << endl;
			commandRepo = 0;
			cout << "Input the command: ";
			cin >> commandRepo;
			while (cin.fail()) {
				cout << "Error" << std::endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> commandRepo;
			}
			cin.ignore();
			if (commandRepo == 1)
				this->ctrlU.next();
			else
				break;
		}
	}
}


void UI_User::run()
{
	
	while (true)
	{
		this->printUserMenu();
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
			this->iterate();
			break;
		case 2:
			this->ctrlU.DisplayFile();
			/*cout<<this->ctrlU.toString();*/
			break;
		case 3:
			this->iterateWatch();
			break;
		
		}
	}



}