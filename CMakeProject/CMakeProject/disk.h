#pragma once
#include <array>
#ifndef DISK_H
#define DISK_H
std::array<int, 8>  load(const std::string inputStr);
void save(const std::string _file, const  std::array<int, 8> & inputArr);
#endif 
