#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

const int XXCentury = 1900;
const string exitProc = "exit";
const string beginProc = "begin";
const string stopProc = "end";
const string statusProc = "status";
//                                          
string fork(time_t inp)
{
	string text = (inp < 10 ? "0" + to_string(inp) : to_string(inp));
	return text;
}
//
string parsingStrToLowerCase(string text)
{
	for_each(text.begin(), text.end(), [](char& c) {
		c = tolower(c);
		});
	return text;
}
//
bool DoWork()
{

	string text = "Stop the current job by typing a word \"end\".\nTo show the status by typing a word \"status\".\n";
	cout << text;
	getline(cin, text);
	text = parsingStrToLowerCase(text);
	if (stopProc == text)
	{
		cout << "Closing this job.\n";
		return false;
	}

	if (statusProc == text)
	{
		time_t now = time(nullptr);
		tm* ltm = localtime(&now);
		time_t  presentYear = XXCentury + ltm->tm_year;
		time_t  presentMonth = 1 + ltm->tm_mon;
		time_t  presentDay = ltm->tm_mday;
		time_t  presentMinutes = ltm->tm_min;
		time_t  presentHour = ltm->tm_hour;
		time_t  presentSec = ltm->tm_sec;

		text = fork(presentHour);
		text += ":";
		text += fork(presentMinutes);
		text += ":";
		text += fork(presentSec);
		text += "  ";
		text += fork(presentDay);
		text += "/";
		text += fork(presentMonth);
		text += "/";
		cout << text << presentYear << endl;
	}
	return true;
}

//
/*          Main func */
int main() {

	bool oneLine = false;
	string name;

	do {
		cout << "\t\tWelcome, User!\nStart the new job to do by typing a word \"begin\".\nTo show the status by typing a word \"status\".\nExit from the program by typing a word \"exit\". " << endl;
		getline(cin, name);
		name = parsingStrToLowerCase(name);

		if (statusProc == name)
		{
			time_t status = time(nullptr);
			tm* ltm = localtime(&status);
			cout << asctime(ltm) << endl;
		}

		if (name == beginProc)
		{
			time_t startCycle = time(nullptr);
			tm* ltm1 = localtime(&startCycle);
			time_t  preSec = ltm1->tm_sec;
			while (DoWork()) {};
			time_t endCycle = time(nullptr);
			tm* ltm2 = localtime(&endCycle);
			time_t  pastSec = ltm2->tm_sec;
			cout << "Elapsed time = ";
			cout << difftime(pastSec, preSec);
			cout << " sec.\n";
		}
		oneLine = (name == exitProc);
	} while (!oneLine);

	return 0;
}
/* End of file */