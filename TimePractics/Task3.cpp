#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>

using namespace std;

struct UserT {

	time_t userSec = getUserSec();
	time_t userMin = getUserMin();

	private:
	  time_t getUserSec()
	{
		int  userSec;
		cout << "Enter seconds: ";
		cin >> userSec;
		if (userSec > 59 || userSec < 0) userSec = 1;
		time_t a =      userSec;
		return a;
	}
	   time_t getUserMin()
	{

		int userMin;

		cout << "Enter minutes: ";
		cin >> userMin;
		if (userMin > 59 || userMin < 0) userMin = 0;
		time_t a = userMin;
		return a;

	}
 };
//
void displayClock(int &y)
{
	using namespace std::literals::chrono_literals;
	int minutes = 0;
	int seconds = 0 ;
	for (size_t k = 0 ; k < y; k++) {

	cout <<setfill(' ') <<setw(55) <<"         TIMER         \n";

	cout <<setfill(' ') <<setw(55) <<" -------------------------\n";

	cout <<setfill(' ') <<setw(31);
	cout <<"| " <<setfill('0') <<setw(2) ;
	cout  <<minutes <<" min  | ";

	cout <<setfill('0') <<setw(2) <<seconds <<" sec\t     |" <<endl;

	cout <<setfill(' ') <<setw(55) <<" -------------------------\n";
	seconds++;
	if (seconds % 60 == 0 ) { minutes++ ; seconds = 0;}
	std::this_thread::sleep_for(1s);
	}
		cout << "\n\t\t\t\tDING! DING! DING!\n";
}
//
/* Main program start */
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Please, enter timer values :\n";
	UserT Tday;
	int endsMin= Tday.userMin ;
	int endsSec =Tday.userSec ;
	endsSec+=60*endsMin;

	displayClock(endsSec);

	system("pause");
	return 0;
}
/* Main program end */


//End of file