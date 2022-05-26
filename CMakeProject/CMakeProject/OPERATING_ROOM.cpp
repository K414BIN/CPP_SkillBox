#include "OPERATING_ROOM.h"

point scalpel(incision &val)
{	
	std::cout << "\nCut from " << val.start.X << " " << val.start.Y << " to " << val.end.X << " ";
	std::cout << val.end.Y << " done.\n";
	return val.end;
}

void hemostat(point val)
{
	std::cout << "\nClamp set to " << val.X << " " << val.Y << "\n";
}

void tweezers(point val)
{
	std::cout << "\nTweezers set to " << val.X << " " << val.Y << "\n";
}

void suture(incision val)
{
	std::cout << "\nSeam from " << val.start.X << " " << val.start.Y << " to " << val.end.X << " ";
	std::cout << val.end.Y << " end. \n";
}
