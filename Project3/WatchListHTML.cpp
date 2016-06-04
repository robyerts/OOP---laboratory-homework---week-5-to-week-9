#include <Windows.h>
#include <shellapi.h>
#include <stdio.h>
#include <assert.h>
#include "WatchListHTML.h"

using namespace std;

void WatchListHTML::writeTutorials()
{
	ofstream f("WatchList.html");	// NO append data
	if (!f.is_open())
		return;
	f << "<!DOCTYPE html>\n";
	f << "<html>" << "\n";
	f << "<head>" << "\n";
	f << "<title>Watchlist</title>" << "\n";
	f << "</head>" << "\n";
	f << "<body>" << "\n";
	f << "<table border = 1>" << "\n";
	f << "<tr>" << "\n";
	f << "<td>Title</td>" << "\n";
	f << "<td>Presenter</td>" << "\n";
	f << "<td>Duration</td>" << "\n";
	f << "<td>Youtube link</td>" << "\n";
	f << "<td>Likes</td>" << "\n";
	f << "</tr>" << "\n";
	for (auto i : Tutorials)
	{
		f << "<tr>";
		f << "<td>" << i.getTitle() << "</td>" << "\n";
		f << "<td>" << i.getArtist() << "</td>" << "\n";
		f << "<td>" << i.getDuration().getMinutes() << ":" << i.getDuration().getSeconds() << "</td>" << "\n";
		f << "<td><a href =" << i.getSource() << "> Aleluia</a></td>" << "\n";

		f << "<td>" << i.getLikes() << "</td>" << "\n";
		f << "</tr>";
	}
	f << "</table>" << "\n";
	f << "</body>" << "\n";
	f << "</html>" << "\n";
	f.close();
}

void WatchListHTML::DisplayFile()
{
	
		ShellExecuteA(NULL, NULL, "chrome.exe", "WatchList.html", NULL, SW_SHOWMAXIMIZED);
	
}