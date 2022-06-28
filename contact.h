
#pragma once
#include <string>
#include <iostream>

#ifndef CONTACT_H
#define CONTACT_H

class Contact
{
    std::string first_name;
    std::string last_name;
    std::string phone_num;
public:
    void setFirstName(std::string text);
    std::string getFirstName();
    void setLastName(std::string text);
    std::string getLastName();
    void setPhoneNum(std::string text);
    std::string getPhoneNum();
    Contact();
    ~Contact();
};
#endif
