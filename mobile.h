#pragma once
#include "contact.h"
#include "serviceSMS.h"
#include "serviceCall.h"
#include <fstream>

#ifndef MOBILE_H
#define MOBILE_H

typedef std::pair<char, char> prefix;
typedef std::pair <int, int> ret_val;

class Mobile 
 {
    const std::string text_file = "contacts.txt";
	Contact createNewContact();
	bool checkStr(const std::string& str);
	const int digitMax = 12;
	ret_val loadPhoneBookNum(std::fstream& os);
	void add(std::string text_file);
public:
	Mobile();
	~Mobile();
	void SMS();
	void Call();

	Contact getOne(std::ifstream& os);	
	void setOne(std::ostream& os, Contact& inputContact);
	void showAll();


	
 };

#endif
