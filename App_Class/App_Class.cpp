#define  _CRT_SECURE_NO_WARNINGS
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <iostream>
#include <ostream>

const int XXCentury = 1900;
const int currentYear= 2022;
const std::string file_ = "audiotracks.txt";

/* Class Track begin */
class Track
{
public:
    
    std::string name;
    std::tm date = createDate();
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
/* Class Track end */
//
/* Class TrackList begin */
class TrackList : Track
{
public:
    std::string file_name = file_;
    // constructor by default
    TrackList() {}
    // modified constructor
    TrackList(std::string text)
    {
        file_name = text;
    }
    // Show 1 Track
    void showOne(std::ostream& out, Track inp)
    {
        int userDay = inp.date.tm_mon;
        int userMonth = 1 + inp.date.tm_mon;
        int userYear = XXCentury + inp.date.tm_year;
        int count = 1;

        std::string  total = (userDay < 10 ? "0" + std::to_string(userDay) : std::to_string(userDay));
        total += "/";
        total += (userMonth < 10 ? "0" + std::to_string(userMonth) : std::to_string(userMonth));
        total += "/" + std::to_string(userYear);
        out << inp.name << "\t";
        out << inp.duration << "\t";
        out << total;
        out << "\n";
    }
  // Show All Track list
    void showClass()
    {
        std::cout << "\tName\t\tDuration\t\tDate\n";
        show (std::cout, tracks);
    }
    //get 1 Track
   Track getOne(int val)
    {
        val--;
        if (val > list_count) val = list_count;
        if (val < 0) val = 0;
        return tracks[val];
    }
    //
private:
	int linesCount = TrackList::howManyLines(file_name) - 1 ;
    std::vector<Track>  tracks  = TrackList::collectRecords(linesCount);
    int list_count = ((!tracks.empty()) ? tracks.size() : 0);
  //
	int howManyLines(std::string file_name)
	{
		std::ifstream file(file_name);
        file.seekg(0, file.beg);
		int i = 0;
		std::string line;
        while (std::getline(file, line)) { i++; }
		file.close();
		return i;
	}
    //
    Track loadRecord(std::ifstream& file)
    {
        Track treck = {};
        using namespace std;
        if (file.bad()) {
            std::cout << "\nError open file!\n";
            return treck;
        }
        string name;
        time_t temp = 9;
       
        getline(file, name);
     
        string strTemp = stringFindChar(name, name.length(), '/', true);
        int userYear = stoi(strTemp);
        size_t sum = name.length() - strTemp.length() - 1;
        strTemp = stringFindChar(name, sum, '/', true);
        int userMonth = stoi(strTemp);
        sum = sum - strTemp.length() - 1;
        strTemp = stringFindChar(name, sum, '\t', true);
        int userDay = stoi(strTemp);
        sum = sum - strTemp.length() - 1;
        strTemp = stringFindChar(name, sum, '\t', true);
        temp = (time_t)stoi(strTemp);
        strTemp = stringFindChar(name, 0, '\t', false);
        treck.duration = temp;
        treck.date.tm_year = userYear - XXCentury;
        treck.date.tm_mon = userMonth - 1;
        treck.date.tm_mday = userDay;
        treck.name = strTemp;
        return treck;
    }
    //
    std::vector<Track> collectRecords(int linesCount)
	{
        bool answer = false;
        std::vector<Track> records;
        records.clear();
        if (linesCount > 0)
        {
            std::ifstream file_in(file_name);
            file_in.seekg(0, file_in.beg);
            do
            {
                records.emplace_back(loadRecord(file_in));
            }  while (linesCount--);
            file_in.close();
        }
        else 
        {
           do 
            {
                records.emplace_back(addRecord());
                std::cout << "Add another audio record? [1 - yes / 0 - no] : ";
                std::cin >> answer;
            } while (answer);

              saveRecords(records);
        }
        return records;
	}
    //
    void saveRecords(std::vector<Track> &records)
    {
        std::ofstream file_out(file_name, std::ios::app);
        if (!file_out.is_open()) {
            std::cout << "\nError open file!\n";
            return;
        }
        show(file_out, records);
        file_out.close();
    }
    //
    void show(std::ostream& file, std::vector<Track>& records)
    {
        for (auto& it : records)
        {
             showOne(file, it);
        }
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
    Track addRecord()
    {
        using namespace std;
        Track  treck = {};
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
        cout << "Please, enter the date of creation of àudio record: ";
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
    std::string stringFindChar(const std::string str, size_t pos, const char ch, bool revers)
    {
        std::string temp = "";
        if (revers) 
        {
            while (pos--) {
                if (str[pos] == ch) { break; }
                temp = str[pos] + temp;
            }
        }
        else
        {
            while (pos != str.length()) {
                if (str[pos] == ch) { break; }
                 temp += str[pos];
                 pos++;
            }
        }
        return temp;
    }    
};
/* Class TrackList end */
//
/* Class Commands begin */
class Commands 
{
public:  
    //
    void pause(int val)
    {
        if (val < 0) return;
        if (val == track_num) 
        {
            std::cout << "Playback paused. Track is #" << track_num;
            std::cout << std::endl;
        }
    }
    //
    void  stop(int val)
    {
        if (val < 0) return;
        if (val == track_num)
        {
            std::cout << "Playback stopped. Track is #" << track_num;
            std::cout << std::endl;
        }
    }
    //
    void exit()
    {
        delete records;
        records = nullptr;
    }
    //
    int  next(int  val)
    {
        return val++;
    }
    //
    int play(int val)
    {
        if (val != track_num) {
            records->showClass();
            std::cout << "\nChoose track to play ";
            std::cin >> track_num;
            std::cout << std::endl;
            std::cout << "Track to play is #" << track_num;
            std::cout << std::endl;
            records->showOne(std::cout, records->getOne(track_num));
        }
        return val;
    }

    int track_num = -1;
private:
    TrackList* records = new TrackList(file_);

};
/* Class Commands end */
//
/* Class Player begin */
class Player 
{
    std::vector <std::string> commands = { "play","pause","exit","stop","next" };

    int itemFromStr(std::string action)
    {
        int item;
        for (item = 0; item < commands.size(); item++)
            if (commands[item] == action) break;
        item++;
        return item;
    }
    int item = ((action.empty()) ? item : itemFromStr(action));

public:   
    std::string action;   

    void Start()
    {
        Commands* ptrCommands = new Commands();
        
        switch (item)
        {
        case 1: ptrCommands->track_num = ptrCommands->play(ptrCommands->track_num);    break;
        case 2: ptrCommands->pause(ptrCommands->track_num);    break;
        case 3: ptrCommands->exit();   exit(8);  break;
        case 4: ptrCommands->stop(ptrCommands->track_num);     break;
        case 5: ptrCommands->track_num = ptrCommands->play(ptrCommands->next(ptrCommands->track_num));    break;
        default:  ptrCommands->track_num = ptrCommands->play(item);    break;
        }
        delete ptrCommands;
        ptrCommands = nullptr;
    }
};
/* Class Player end */
//
/*       main func */
int main() {
 
	setlocale(LC_ALL, "Russian");
    std::string action;
    Player* ptrCommands = new Player();
    std::cout << "\n\tWelcome to MyPlayer(tm)! \n";
    do {
        std::cout << "The MyPlayer has these commands:\n";
        std::cout << "1) Play\n";
        std::cout << "2) Pause\n";
        std::cout << "3) Exit\n";
        std::cout << "4) Stop\n";
        std::cout << "5) Next\n";
        std::cout << "\nType commmand here: ";
        std::cin >> action;
        ptrCommands->action = action;
        ptrCommands->Start();
    } while (true);

     delete ptrCommands;
     ptrCommands = nullptr;
     
	system("pause");
	return 0;
}

