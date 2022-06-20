
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include <ostream>
#include "mobile.h"


int main()
{
	setlocale(LC_ALL, "en-US");
	Mobile* cellPhone = new Mobile();

	delete cellPhone;
	cellPhone = nullptr;

	system("pause");
	return 0;
}

// End of file.