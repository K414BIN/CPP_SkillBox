#pragma once
#include <array>
#include <string>
#ifndef KBD_H
#define KBD_H

const std::string match = "0123456789-.";
bool abnormalSymbols(const std::string& str, const std::string& match);
 std::array<int, 8>  inputDigits( std::array<int, 8> &buffer);
#endif 
