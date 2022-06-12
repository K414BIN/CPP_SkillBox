#include "Track.h"

 std::tm Track::createDate()
 {
        std::tm tm{};
        std::time_t now = time(nullptr);
        std::tm* local = std::localtime(&now);
        tm.tm_year = local->tm_year;
        tm.tm_mon = local->tm_mon;
        tm.tm_mday = local->tm_mday;
        tm.tm_hour = 0;
        tm.tm_min = 0;
        tm.tm_sec = 0;
        return tm;
 }