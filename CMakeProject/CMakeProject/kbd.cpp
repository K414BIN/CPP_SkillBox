#include <iostream>
#include <array>
#include <string>
#include "kbd.h"

typedef  std::array<int, 8> Tarray;

//
bool abnormalSymbols(const std::string& str, const std::string& match)
{
    std::size_t  found = str.find_first_not_of(match);
    if (found != std::string::npos) return false;
    return true;
}
//
Tarray inputDigits(Tarray buffer)
{
    int size = sizeof(buffer) / sizeof(buffer[0]);
    std::cout << "\nPlease, enter eight integer numbers. \n";
    for (size_t i = 0; i < size; i++) {

        std::cout << "Input for " << i + 1 << " number: ";
        std::cin.sync();
        std::string inputStr;
        std::cin >> inputStr;
        if (abnormalSymbols(inputStr, match)) buffer[i] = std::stoi(inputStr);
        else  buffer[i] = -1;
    }
     return buffer;
};

