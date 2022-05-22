#pragma once

#ifndef DISK_H
#define DISK_H
typedef  std::array<int, 8> Tarray;
Tarray load(const std::string inputStr);
void save(const std::string _file, const Tarray& inputArr);
#endif 
