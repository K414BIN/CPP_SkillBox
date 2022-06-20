#include "contact.h"

void Contact::setFirstName(std::string text)
{
	first_name = text;
}

std::string Contact::getFirstName()
{
	return 	first_name;
}

void Contact::setLastName(std::string text)
{
	last_name = text;
}

std::string Contact::getLastName()
{
	return last_name;
}

void Contact::setPhoneNum(std::string text)
{
	phone_num = text;
}

std::string Contact::getPhoneNum()
{
	return phone_num;
}
