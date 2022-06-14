#include "serviceSMS.h"

serviceSMS(std::string phone_num ) : Contact (first_name,last_name,phone_num)
{
  
}
//
void makeIt() 
 {
		std::cout << "SMS sent to "<< Contact.phone_num << std::endl;
 }