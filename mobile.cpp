#include "mobile.h"

using namespace std;

Mobile::Mobile()
{

	fstream file_s;
	file_s.open(text_file, fstream::in | fstream::out | fstream::app);
	if (!file_s.is_open())
	{
		cerr << "Error: file could not be opened" << endl;
		file_s.close();
		exit(1);
	}
	else
	{
		int lines_all = 0;
		int user_num = 0;
		ret_val results = loadPhoneBookNum(file_s);
		user_num = results.first;
		lines_all = results.second;
		file_s.close();

		if (user_num < 1)
		{
			add(text_file);
		}
	}
}

void Mobile::SMS()
{
}

Mobile::~Mobile()
{
}


ret_val Mobile::loadPhoneBookNum(std::fstream& os)
{
	int i = 0;
	int j = 0;
	string temp;
	os.seekg(0, os.beg);
	if (os.good())
	{
		while (getline(os, temp))
		{
			i++;
			cout << i << ") " << temp << "\n";
		}
	}
	else cout << "\nError opening file!\n";

	if (i > 0)
	{
		cout << "If the desired entry is missing, select 0 to add. ";
		cout << "Please, choose number :";
		cin >> j;
		if (j > i) j = i;
		if (j < 0) j = 0;
	}
	ret_val result ( j, i );
	return result;
}

void Mobile::Call()
{
}

Contact Mobile::getOne(std::ifstream& os)
{
	string inputStr[4];
	Contact book = {};
	
	os >> inputStr[0];// >> inputStr[1] >> inputStr[2] >> inputStr[3] >> inputStr[4];
	std::cout << "\n" << inputStr[0] << "\n";
	std::cout << "\n" << inputStr[1] << "\n";
	std::cout << "\n" << inputStr[2] << "\n";
	std::cout << "\n" << inputStr[3] << "\n";
	std::cout << "\n" << inputStr[4] << "\n";

	book.setFirstName(inputStr[1]);
	book.setLastName(inputStr[2]);
	book.setPhoneNum(inputStr[3]);
	return book;
}


void Mobile::setOne(std::ostream& os, Contact& inputContact)
{
		os << inputContact.getFirstName();
		os << "\t";
		os << " ";
		os << "\t";
		os << inputContact.getLastName();		
		os << "\t";
		os << " ";
		os << "\t";
		os << inputContact.getPhoneNum();
		os << "\n";
	
}

void Mobile::showAll()
{
	
	cout << "First name\t";
	cout << "\tLast  name\t";
	cout << "\tPhone number\n\n";

}

void Mobile::add(string text_file)
{
	int y = 4;
	std::ofstream file_s(text_file, std::ios::app);
	if (!file_s.is_open())
	{
		cerr << "Error: file could not be opened" << endl;
		file_s.close();
		exit(2);
	}
	while (y)
	{
		Contact book = {};
		book = createNewContact();
		setOne(file_s, book);
		std::cout << "Add another contact in phonebook [1 - yes / 0 - no]: ";
		std::cin >> y;
	}
	file_s.close();
}

bool Mobile::checkStr(const std::string& str)
{
	prefix model('+', '7');
	bool allNOK = true;
	if (str.length() != digitMax)	return allNOK;
	const std::string match1 = "0123456789+";
	std::size_t  found = str.find_first_not_of(match1);
	if (found != std::string::npos) return allNOK;	
	prefix input(str[0], str[1]);
	if ( input == model ) allNOK = false;

	return allNOK;
}

Contact Mobile::createNewContact()
{
	Contact book;
	string inputStr;
	
	cin.sync();
	cout << "\n\tWelcome to the menu for creating a new phonebook contact!\n";
	do
	{   cout << "Please, enter the first name:\n";		
		getline(cin, inputStr);
	
	} while (inputStr.length() < 2);
	book.setFirstName(inputStr);
	cin.sync();
	do
	{	cout << "Please, enter the last name: \n";	
		getline(cin, inputStr);
	
	} while (inputStr.length() < 2);
	book.setLastName(inputStr);
	cin.sync();
	do
	{	cout << "Please, enter the phone number. Make sure the number starts with +7 and is 10 digits long: \n";
		getline(cin, inputStr);
	} while (checkStr(inputStr));
	book.setPhoneNum(inputStr);
	cin.sync();
	return book;
}