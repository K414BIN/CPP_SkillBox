#pragma once

#include <array>
#ifndef CMakeProject_H
#define CMakeProject_H

const std::string file = "data.txt";
std::array<std::string, 6 > comands = { "exit", "input", "display", "load", "save", "sum" };
int caseOfItems(const std::string text, std::array<std::string, 6 > commands);
std::string parsingStrToLowerCase(const std::string text);

#endif 