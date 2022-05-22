#pragma once

#ifndef KBD_H
#define KBD_H
typedef  std::array<int, 8> Tarray;
const std::string match = "0123456789-.";
bool abnormalSymbols(const std::string& str, const std::string& match);
Tarray inputDigits(Tarray buffer);
#endif 
