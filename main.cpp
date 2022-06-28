

#include <iostream>
#include "mobile.h"



int main()
{
	setlocale(LC_ALL, "en-GB");

	Mobile* cellPhone = new Mobile();
	cellPhone->showAll();
	delete cellPhone;
	cellPhone = nullptr;

	system("pause");
	return 0;
}

// End of file.