#include "ram.h"
#include <iostream>
#include <array>

 std::array<int, 8>  write(const  std::array<int, 8>  &inArray)
{
     std::cout << "Buffer of numbers stored into RAM!\n";
   
     return inArray;      
}

 std::array<int, 8>  read(const  std::array<int, 8>  &inArray)
{
    std::cout << "Buffer of numbers loaded from RAM!\n";

    return inArray;
}
