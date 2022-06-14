#include "contact.h"

Contact::Contact(std::string _first_name,std::string _last_name,std::string _phone_num)
{
    first_name =_first_name;
    last_name = _last_name;
    phone_num = _phone_num;
       
}
//
void Contact::makeIt()
 { 
    std::cerr << "Error. Not available for base type.\n" ;
 }