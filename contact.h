
#pragma once

#include <iostream>


#ifndef CONTACT_H
#define CONTACT_H
class Contact
{
    public:
	std::string first_name;
    std::string last_name;
    std::string phone_num;
	 Contact(std::string _first_name,std::string _last_name,std::string _phone_num);
	 ~Contact();
    virtual void makeIt() ;
};
#endif
