#pragma once

#include <string>
#include <iostream>
#include "contact.h"

#ifndef SERVICESMS_H
#define SERVICESMS_H

class serviceSMS: public Contact 
{
	public:
   	 serviceSMS(std::string phone_num ) : Contact (first_name,last_name,phone_num);
	 ~serviceSMS();
     void makeIt() ;
};
#endif

