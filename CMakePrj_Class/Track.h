#pragma once

#include <iostream>
#include <ctime>

#ifndef TRACK_H
#define TRACK_H

class Track
{
public:
    std::string   name;
    std::tm     date = createDate();
    std::time_t duration;
private:
    std::tm createDate();
};
#endif