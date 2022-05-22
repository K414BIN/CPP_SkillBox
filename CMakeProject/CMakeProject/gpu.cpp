#include <iostream>
#include "gpu.h"

typedef  std::array<int, 8> Tarray;

void VGAOutput(const Tarray &inArray)
{
    int len = sizeof(inArray) / sizeof(inArray[0]);
    
    std::cout << "\nRAM contains this numbers :\n\n";
    for (size_t j = 0; j < len; j++ )
                std::cout << "\t" << inArray[j];
    std::cout << "\n";
}
