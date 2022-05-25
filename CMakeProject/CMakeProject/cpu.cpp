#include "cpu.h"
#include <array>
#include <iostream>



void compute(const  std::array<int, 8>  &inArray)
{
    int len = sizeof(inArray) / sizeof(inArray[0]);
    int sum = 0;
    
    for (size_t j = 0; j < len; j++)
    sum += inArray[j];
    std::cout << "\nResult of computing these numbers = ";
    std::cout << sum << std::endl;
}
