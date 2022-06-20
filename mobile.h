#pragma once
#include "contact.h"
#include "serviceSMS.h"
#include "serviceCall.h"
#include <string>
#include <iostream>
#include <vector>

#ifndef MOBILE_H
#define MOBILE_H

class Mobile 
 {
	std::vector<Contact> list;
	public:
	Mobile();
	~Mobile();
	void showOne(Contact& inputContact);
	Contact createNewContact();
	void SMS();
	void Call();
	void add(Contact &inputContact);
	void showAll();
 };

#endif
