#define  _CRT_SECURE_NO_WARNINGS
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include <ostream>

const int XXCentury = 1900;
const int currentYear= 2022;
const std::string file_ = "audiotracks.txt";

class Track
{
public:
    std::string   name;
    std::tm     date = createDate();
    std::time_t duration;
private:
    std::tm createDate() {
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
};

class Player
{
public:

    std::string file_name;
    Player(std::string text)
    {
        file_name = text;
        std::vector<Track> records = collectRecords(howManyLines(file_name));
    }

    void show()
    {
        showClass(std::cout, records);
    }

private :
    std::vector<Track> records;

    std::vector<Track> collectRecords(int val)
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
    bool is_leap_year(int year)
    {
        return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
    }
    //
    int days(int year, int month)
    {
        bool value = is_leap_year(year);
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
    std::string stringFindChar(const std::string str, int pos, const char ch)
    {
        std::string temp = "";
        while (pos--) {
            if (str[pos] == ch) { break; }
            temp = str[pos] + temp;
        }
        return temp;
    }
    //
    void saveRecords(std::vector <Track>& vector)
    {
        std::ofstream file_out(file_, std::ios::app);
        if (!file_out.is_open()) {
            std::cout << "\nError open file!\n";
            return;
        }
        showClass(file_out, vector);
        file_out.close();
    }
    //
    Track loadRecord(std::ifstream& file)
    {
        using namespace std;
        Track treck;
        if (file.bad()) return treck;
        string name;
        int userDay;
        int userMonth;
        int userYear;
        time_t temp;
        int sum;
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
    /*                      */        
    void showClass(std::ostream& file, std::vector <Track> t)
    {
        for (size_t i = 0; i < t.size(); i++)
        {
            showAllFields(file, t[i]);
        }
    }
    /*                  */        
    Track addRecord()
    {
        using namespace std;
        Track treck;
        string name;
        int userDay;
        int userMonth;
        int userYear;
        time_t temp;
        do {
            cout << "Please, enter the name of audio record: ";
            getline(cin, name);
        } while (name.length() < 2);
        treck.name = name;
        cout << endl;
        cout << "Please, enter the date of creation of аudio record: ";
        cout << endl;
        //      
        do {
            cout << "Year: ";
            cin >> name;
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
            cout << "Month: ";
            cin >> name;
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
        int compDays = days(userYear, userMonth);
        do {
            cout << "Day: ";
            cin >> name;
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
        cout << endl;
        cout << "Please, enter the duration of the audio record: ";
        cin >> temp;
        treck.duration = temp;
        cout << endl;
        return treck;
    }
    //
    void showAllFields(std::ostream& out, Track inp)
    {
        int userDay = inp.date.tm_mon;
        int userMonth = 1 + inp.date.tm_mon;
        int userYear = XXCentury + inp.date.tm_year;
        std::string total = "Date of creation: ";
        total += (userDay < 10 ? "0" + std::to_string(userDay) : std::to_string(userDay));
        total += "/";
        total += (userMonth < 10 ? "0" + std::to_string(userMonth) : std::to_string(userMonth));
        total += "/" + std::to_string(userYear);

        out << "Name of track: " << inp.name;
        out << "\n";
        out << "Duration of audio record: " << inp.duration;
        out << "\n";
        out << total;
        out << "\n";
    }
    //
    int howManyLines(std::string file_name)
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
};
//
int main()
{
    setlocale(LC_ALL, "Russian");
   
    Player MyPlayer(file_);
    MyPlayer.show();
    system("pause");
    return 0;
}
