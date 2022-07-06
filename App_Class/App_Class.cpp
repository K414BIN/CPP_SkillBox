#define  _CRT_SECURE_NO_WARNINGS
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <iostream>
#include <ostream>
#include <tuple>

const int XXCentury = 1900;
const int currentYear= 2022;
const std::string file_ = "audiotracks.txt";

/* Class TrackList begin */
class TrackList
{
    //
private:
    /* Class TrackList items */

    std::string file_name = file_;

    /* inner Class Track begin */
    class Track
    {
        /* Class Track items */
        std::string name;
        std::tm date = createDate();
        std::time_t duration;
        /* Class Track functions */
        std::tm createDate()
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
    public:
        /* Class Track functions */
        //
        void setDate(int userDay, int userMonth, int userYear)
        {
           
           date.tm_year = userYear - XXCentury;
           date.tm_mon = userMonth - 1;
           date.tm_mday = userDay;
           
        }
        //
        std::tuple <int, int, int> getDate()
        {
            int userDay = date.tm_mon;
            int userMonth = 1 + date.tm_mon;
            int userYear = XXCentury + date.tm_year;
            int count = 1;
            return std::tie(userDay, userMonth, userYear);
        }
        //
        void setName(const std::string& text)
        {
            name = text;
        }
        //
        std::string getName() const
        {
            return name;
        }
        //
        void setDuration(const std::time_t& time)
        {
            duration = time;
        }
        //
        std::time_t getDuration() const
        {
            return duration;
        }
    };
    /* inner Class Track end */
public:
    /* Class TrackList functions */

    void setFilename(const std::string& text)
    {
        file_name = text;
    }
    //
    // Show 1 Track
    void showOne(std::ostream& out, Track inp)
    {
        int userDay;
        int userMonth;
        int userYear;
        std::tie(userDay, userMonth, userYear) = inp.getDate();
        int count = 1;

        std::string  total = (userDay < 10 ? "0" + std::to_string(userDay) : std::to_string(userDay));
        total += "/";
        total += (userMonth < 10 ? "0" + std::to_string(userMonth) : std::to_string(userMonth));
        total += "/" + std::to_string(userYear);
        out << inp.getName() << "\t";
        out << inp.getDuration() << "\t";
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
   int getRecordsCounter() const
   {
       return list_count;
   }

private:
    /* Class TrackList items */
	int linesCount = TrackList::howManyLines(file_name) - 1 ;
    std::vector<Track>  tracks  = TrackList::collectRecords(linesCount);
    int list_count = ((!tracks.empty()) ? tracks.size() : 0);

    /* Class TrackList  functions */
    //
	int howManyLines(const std::string& file_name)
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
        treck.setDuration(temp);
        treck.setDate(userDay, userMonth, userYear);
        treck.setName(strTemp);
        
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
    bool is_leap_year(int &year)
    {
        return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
    }
    //
    int days(int &year, int &month)
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
        treck.setName(name);
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
        treck.setDate(userDay, userMonth, userYear);
        cout << endl;
        cout << "Please, enter the duration of the audio record: ";
        cin >> temp;
        treck.setDuration(temp);
        cout << endl;
        
        return treck;
    }
    //
    std::string stringFindChar(const std::string& str, size_t pos, const char ch, bool revers)
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
/* Class Player begin */
class Player 
{
private:
    /* inner Class Commands begin */
    class Commands
    {
    public:
        /* Class Commands functions */
        //
        void pause(int val)
        {
           std::cout << "Playback paused. Track is #" << val << std::endl;
        }
        //
        void stop(int val)
        {
            std::cout << "Playback stopped. Track is #" << val << std::endl;
        }
        //
        bool exit()
        {
            return false;
        }
        //
        void play(int val)
        {
           std::cout << "Track to play is #" << val<< std::endl;
        }
    };
    /* inner Class Commands end */

    /* Class Player items */
     std::vector <std::string> commands = { "play","pause","exit","stop","next" };
    /* Class Player functions */
    int itemFromStr(std::string action)
    {
        int item;
        for (item = 0; item < commands.size(); item++)
            if (commands[item] == action) break;
        item++;
        return item;
    }
    //
    std::string setCommnand()
    {
        std::string action;
   
        std::cout << "The MyPlayer has these commands:\n";
        std::cout << "1) Play\n";
        std::cout << "2) Pause\n";
        std::cout << "3) Exit\n";
        std::cout << "4) Stop\n";
        std::cout << "5) Next\n";
        std::cout << "\nType commmand here: ";
        std::cin >> action;
        return action;
    }
    //Randomize tracks
    int recNow(int max) {
        int x;
        do {
            x = 1 + std::rand() / ((RAND_MAX + 1u) / max);
        } while (x >= max);
        return x;
    }
public:   
    /* Class Player functions */
      void Start(std::string text)
    {
        int max_records = 0;
        int track_num = -32;
        Commands* ptrCommands = new Commands();
        TrackList* ptrTrackList = new TrackList();
        ptrTrackList->setFilename(text);
        ptrTrackList->showClass();
        max_records = ptrTrackList->getRecordsCounter();
        std::cout << "\nChoose track ";
        std::cin >> track_num;
     
        if ((track_num < 1) || (max_records < track_num)) track_num = 1;
        bool done = false;
        bool log_out = true;
        do {
            std::cout << std::endl;
            int item = itemFromStr(setCommnand());
            switch (item)
            {
            case 5: track_num = recNow(max_records); if (max_records < track_num) track_num = 1;
            case 1: if (!done )
                    {
                    ptrCommands->play(track_num); ptrTrackList->showOne(std::cout, ptrTrackList->getOne(track_num)); done = true;
                    }
                    break;
            case 2: if (done) ptrCommands->pause(track_num); done = false; break;
            case 3: log_out = ptrCommands->exit(); break;
            case 4: if (done) ptrCommands->stop(track_num); done = false; break;

            }
        } while (log_out);
        delete ptrCommands;
        ptrCommands = nullptr;
        delete ptrTrackList;
        ptrTrackList = nullptr;
    }
};
/* Class Player end */
//
/*       main func */
int main() {
    std::srand(std::time(nullptr));
	setlocale(LC_ALL, "Russian");
    std::string action;
    Player* ptrPlayer= new Player();
    std::cout << "\n\tWelcome to MyPlayer(tm)! \n";
    std::cout << "Please, type file name of track lists: ";
    std::cin >> action;
    if (action.length() < 2) action = file_;
    ptrPlayer->Start(action);
    delete ptrPlayer;
    ptrPlayer = nullptr;
     
	system("pause");
	return 0;
}

