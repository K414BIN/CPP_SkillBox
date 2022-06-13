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
   
    Player(std::string text,bool ask);
    void play(Track& track);
    void pause(Track& track);
    void stop(Track& track);
    void next(Track& track);
    void exit();
    void show();

private:
    std::vector<Track> records;
    int  total_records;
    int  current_record;
    std::vector<Track> getVecRecords();
    std::vector<Track> collectRecords(int val);
    std::string stringFindChar(const std::string str, size_t pos, const char ch);
    bool is_leap_year(int year);
    void saveRecords(std::vector <Track>& vector);
    void showClass(const std::vector <Track>& arr, std::ostream& file);
    void showAllFields(const Track& inp, std::ostream& file);
    Track addRecord();
    Track loadRecord(std::ifstream& file);
    int howManyLines(std::string file_name);
    int days(int year, int month);
    
};
#endif