#include <iostream>
#include "CMakeProject.h"
#include "OPERATING_ROOM.h"

//
int main()
{

	std::cout << "\n\t\t\tWelcome to our clinic!\nAccording to the updated version of your DMS, only the robot surgeon assembled by scouts is available to you.\n";
	std::cout << "The robot perceives only two coordinates and only two points. The team of our clinic wishes you good luck! Enter the coordinates of the points sequentially:\n";
	incision bodyIncision;
	point cut = scalpel(bodyIncision);
	hemostat(cut);
	tweezers(cut);
	suture(bodyIncision);
	std::cout << "\nCongratulations! \nYou manage to survive! Goodbye!\n";
	
	system("pause");
	return 0;
}
