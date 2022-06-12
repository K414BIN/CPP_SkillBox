#pragma once

#include "Track.h"
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include <ostream>

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    const int XXCentury = 1900;
    const int currentYear = 2022;


    std::string file_name;
    void show();
    Player(std::string text);

private:
    std::vector<Track> records;

    std::vector<Track> collectRecords(int val);
    std::string stringFindChar(const std::string str, int pos, const char ch);
    bool is_leap_year(int year);
    void saveRecords(std::vector <Track>& vector);
    void showAllFields(std::ostream& out, Track inp);
    void showClass(std::ostream& file, std::vector <Track>  arr);
    Track addRecord();
    Track loadRecord(std::ifstream& file);
    int howManyLines(std::string file_name);
    int days(int year, int month);
};
#endif