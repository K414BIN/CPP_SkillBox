#pragma once


#ifndef CMakeProject_H
#define CMakeProject_H
typedef  std::array<int, 8> Tarray;
const std::string file = "data.txt";
std::array<std::string, 6 > comands = { "exit", "input", "display", "load", "save", "sum" };
int caseOfItems(const std::string text, std::array<std::string, 6 > commands);
std::string parsingStrToLowerCase(const std::string text);

#endif 