#include "Player.h"
#include "Track.h"

// Constructor    
Player::Player(std::string text, bool ask = false)
    {
        file_name = text;
        total_records = howManyLines(file_name);
        std::vector<Track> records = collectRecords(total_records);
        if (ask) showClass(records,std::cout);
    }
//
void Player::show()
{
   showClass(getVecRecords(), std::cout);
}
//
void Player::play(Track& track)
{
   showAllFields(track,std::cout);
}
//
void Player::pause(Track& track)
{
}
//
void Player::stop(Track& track)
{
}
//
void Player::next(Track& track)
{
}
//
void Player::exit()
{
}
//
std::vector<Track> Player::getVecRecords()
{
 //   std::cout << "Vector of records has size " << records.size() << std::endl;
    return records;
}
//
std::vector<Track> Player::collectRecords(int val)
{
        std::vector <Track> result;
        int y = 1;
        int counter = val / 3;

        if (val < 3) {
            while (y)
            {
                Track treck = addRecord();
                result.push_back(treck);
                std::cout << "Add another audio record? [1 - yes / 0 - no] : ";
                std::cin >> y;
                saveRecords(result);
            }
        }
        else
        {
            std::ifstream file_in(file_name);
            while (counter--)
            {
                result.push_back(loadRecord(file_in));
            }
            file_in.close();
        }

        return result;
}
//
 bool Player::is_leap_year(int year)
    {
        return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
    }
//
 int Player::howManyLines(std::string file_name)
 {
     using namespace std;
     ifstream file(file_name);

     file.seekg(0, file.beg);
     int i = 0;
     string line;
     while (getline(file, line))
     {
         i++;

     }
     file.close();
     return i;
 }
 //
int Player::days(int year, int month)
{
        bool value = Player::is_leap_year(year);
        int days = 28;
        switch (month) {
        case 2:  if (value) days++;  break;
        case 4:
        case 6:
        case 9:
        case 11: days += 2; break;
        default: days += 3; break;
        }
        return days;
}
//
std::string Player::stringFindChar(const std::string str, size_t pos, const char ch)
{
        std::string temp = "";
        while (pos--) {
            if (str[pos] == ch) { break; }
            temp = str[pos] + temp;
        }
        return temp;
}
//
void Player::saveRecords(std::vector <Track>& vector)
{
        std::ofstream file_out(file_name, std::ios::app);
        if (!file_out.is_open()) {
            std::cout << "\nError open file!\n";
            return;
        }
        showClass(vector,file_out);
        file_out.close();
}
//
Track Player::loadRecord(std::ifstream& file)
{
        using namespace std;
        Track treck;
        if (file.bad()) return treck;
        string name;
        int userDay;
        int userMonth;
        int userYear;
        time_t temp;
        size_t sum;
        getline(file, name);
        treck.name = stringFindChar(name, name.length(), ':');
        getline(file, name);
        string strTemp = stringFindChar(name, name.length(), ':');
        temp = (time_t)stoi(strTemp);
        treck.duration = temp;
        getline(file, name);
        strTemp = stringFindChar(name, name.length(), ':');
        name = stringFindChar(strTemp, strTemp.length(), '/');
        userYear = stoi(name);
        sum = strTemp.length() - name.length() - 1;
        name = stringFindChar(strTemp, sum, '/');
        userMonth = stoi(name);
        name = stringFindChar(strTemp, sum - name.length() - 1, ' ');
        userDay = stoi(strTemp);
        treck.date.tm_year = userYear - XXCentury;
        treck.date.tm_mon = userMonth - 1;
        treck.date.tm_mday = userDay;

        return treck;
}
//
Track Player::addRecord()
{
        Track treck;
        std::string name;
        int userDay;
        int userMonth;
        int userYear;
        time_t temp;
        do {
           std::cout << "Please, enter the name of audio record: ";
           std::getline(std::cin, name);
        } while (name.length() < 2);
        treck.name = name;
        std::cout << "\nPlease, enter the date of creation of аudio record: \n";
        //      
        do {
            std::cout << "Year: ";
            std::cin >> name;
            try
            {
                userYear = stoi(name);
            }
            catch (const std::exception&)
            {
                userYear = currentYear;
            }

        } while (userYear > currentYear || userYear < XXCentury);
        //
        do {
            std::cout << "Month: ";
            std::cin >> name;
            try
            {
                userMonth = stoi(name);
            }
            catch (const std::exception&)
            {
                userMonth = 5;
            }
        } while (userMonth < 1 || userMonth > 12);
        //
        int compDays = Player::days(userYear, userMonth);
        do {
            std::cout << "Day: ";
            std::cin >> name;
            try
            {
                userDay = stoi(name);
            }
            catch (const std::exception&)
            {
                userDay = 9;
            }
        } while (userDay < 1 || userDay > compDays);
        //
        treck.date.tm_year = userYear - XXCentury;
        treck.date.tm_mon = userMonth - 1;
        treck.date.tm_mday = userDay;
 
        std::cout << "\nPlease, enter the duration of the audio record: ";
        std::cin >> temp;
        treck.duration = temp;
        
        return treck;
}
//
void Player::showAllFields(const Track& inp, std::ostream& file)
{
    int userDay = inp.date.tm_mon;
    int userMonth = 1 + inp.date.tm_mon;
    int userYear = XXCentury + inp.date.tm_year;
    std::string total = "Date of creation: ";
    total += (userDay < 10 ? "0" + std::to_string(userDay) : std::to_string(userDay));
    total += "/";
    total += (userMonth < 10 ? "0" + std::to_string(userMonth) : std::to_string(userMonth));
    total += "/" + std::to_string(userYear);
    total += "\n";

    file << "Name of track: " << inp.name;
    file << "\n";
    file << "Duration of audio record: " << inp.duration;
    file << "\n";
    file << total;
}
//
void Player::showClass(const std::vector <Track>& arr, std::ostream& file)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        showAllFields(arr[i], file);
    }
}