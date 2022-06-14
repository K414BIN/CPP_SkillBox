#pragma once
#include "contact.h"
#include "serviceCall.h"
#include "serviceSMS.h"
#include <string>
#include <iostream>
#include <map>

#ifndef MOBILE_H
#define MOBILE_H

class Mobile 
 {
	public:
	
	Mobile();
	~Mobile();
	void exit();
	void SMS();
	void Call();

 };

#endif
