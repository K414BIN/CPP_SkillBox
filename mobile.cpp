#include "mobile.h"

Mobile::Mobile()
{
	if (list.empty()) add(createNewContact());
	else showAll();
}

void Mobile::SMS()
{
}

Mobile::~Mobile()
{
}

void Mobile::Call()
{
}

void Mobile::showOne(Contact& inputContact)
{
	std::cout << "\t\tList of contacts: \n";
	std::cout << "First name .... ";
	std::cout << inputContact.getFirstName();
	std::cout << std::endl;
	std::cout << "Last  name .... ";
	std::cout << inputContact.getFirstName();
	std::cout << std::endl;
	std::cout << "Phone number... ";
	std::cout << inputContact.getPhoneNum();
	std::cout << std::endl;
}

void Mobile::showAll()
{
	for (size_t i = 0; i < list.size(); i++)
	{
		showOne(list[i]);
	}
}


void Mobile::add(Contact &inputContact)
{
	list.emplace_back(inputContact);
}

Contact Mobile::createNewContact()
{
	using namespace std;
	Contact book;
	string inputStr;
	cout << "\n\tWelcome to the menu for creating a new phonebook contact!\n";
	cout << "Please, enter the first name:\n";
	getline(cin, inputStr);
	book.setFirstName(inputStr);
	cout << "Please, enter the last name: \n";
	getline(cin, inputStr);
	book.setLastName(inputStr);
	cout << "Please, enter the phone number. Make sure the number starts with +7 and is 10 digits long: \n";
	getline(cin, inputStr);
	book.setPhoneNum(inputStr);
	return book;
}
