#include "gpu.h"
#include <array>
#include <iostream>


void VGAOutput(const  std::array<int, 8>  &inArray)
{
    int len = sizeof(inArray) / sizeof(inArray[0]);
    
    std::cout << "\nRAM contains this numbers :\n\n";
    for (size_t j = 0; j < len; j++ )
                std::cout << "\t" << inArray[j];
    std::cout << "\n";
}
