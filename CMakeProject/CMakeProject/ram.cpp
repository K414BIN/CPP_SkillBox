#include <iostream>
#include "ram.h"

typedef  std::array<int, 8> Tarray;

Tarray write(const Tarray &inArray)
{
     std::cout << "Buffer of numbers stored into RAM!\n";
   
     return inArray;      
}

Tarray read(const Tarray &inArray)
{
    std::cout << "Buffer of numbers loaded from RAM!\n";
   
    return inArray;
}
