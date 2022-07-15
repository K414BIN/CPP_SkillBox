#define  _CRT_SECURE_NO_WARNINGS

#include <string>
#include <tuple>      
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>    


const int XXCentury = 1900;
const int currentYear= 2022;
const std::string file_n = "audiotracks.txt";

using namespace std;
/* Class TrackList begin */
class TrackList
{
/* +++++++++++++++++ */    
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
        void setDate(const int userMonth, const int userYear)
        {
           date.tm_year = userYear - XXCentury;
           date.tm_mon = userMonth - 1;               
        }
        //
        std::tuple < int, int> getDate() const
	{         
            int userMonth = 1 + date.tm_mon;
            int userYear = XXCentury + date.tm_year;
            int count = 1;
            return std::tie(userMonth, userYear);
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
 /* Class TrackList functions */
  /* +++++++++++++++++ */    
int howManyLines(const std::string& file_name)/* showAll func*/
{
	std::ifstream file(file_name);
	int i = 0;
	if (file.good()) 
	{
			std::string line;
			file.seekg(0, file.beg);
			while (std::getline(file, line))
			{ 
									i++;
									std::cout << i<<") "<< line <<std::endl;
			}			
	}
	file.close();
	return i;
}
/* +++++++++++++++++ */    
public:
void showOne(std::ostream& out, Track* inp)
{
        int userMonth;
        int userYear;
        std::tie( userMonth, userYear) = inp->getDate();    
        std::string total = (userMonth < 10 ? "0" + std::to_string(userMonth) : std::to_string(userMonth));
        total += "/" + std::to_string(userYear);
        out << inp->getName() << "\t";
        out << inp->getDuration() << "\t";
        out << total;
        out << "\n";
}
/* +++++++++++++++++ */    
std::string setFilename( )
{
	std::cout <<"\nPlease, enter filename for track list ";
	std::string text;
	getline(std::cin , text ); 
	if (text.length() < 2) text = file_n;
	return text;
}
/* +++++++++++++++++ */    
std::string getFilename() const
{
	return  file_name;
}
 /* Class TrackList functions */
private:
/* +++++++++++++++++ */  
Track addRecord()
{   
        Track  treck = {};
        string name;
	int userMonth;
        int userYear;
        time_t temp;
        do {
            cout << "Please, enter the name of audio record: ";
            getline(cin, name);
        } while (name.length() < 2);
        treck.setName(name);
        cout << endl;
        cout << "Please, enter the date of creation of audio record: ";
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
        treck.setDate( userMonth, userYear);
        cout << endl;
        cout << "Please, enter the duration of the audio record: ";
        cin >> temp;
        treck.setDuration(temp);
        cout << endl;
        
        return treck;
    }
/* +++++++++++++++++ */ 
void saveRecord(Track* record, std::string& file_name)
    {
        std::ofstream file_out(file_name, std::ios::app);
        if (file_out.good()) showOne(file_out, record);            
        else std::cout << "\nError open output file!\n";
        file_out.close();
    }
 /* +++++++++++++++++ */    
int createList(std::string& file_name)
{
	bool answer = false;
	int counter =0;
	do {
	counter++;	
	Track* ptr_addRecord = new Track();
	*ptr_addRecord = addRecord();
	saveRecord(ptr_addRecord, file_name);
	std::cout << "Add another audio record? [1 - yes / 0 - no] : ";
	std::cin >> answer;
	delete ptr_addRecord;
	ptr_addRecord = nullptr;	
	} while (answer);	
	return counter;
}
/* +++++++++++++++++ */    
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
/* +++++++++++++++++ */    
public:
Track* loadOneRecord(const std::string& file_name, int num)
{
	std::string serviceStr1;
	Track* ptr_Track = new Track();    
	std::ifstream file(file_name);
	if (!file.good()) {
            std::cout << "\nError open file!\n";
            return ptr_Track;
        }
	for (size_t i = 0; i <= num;  i++)  std::getline(file, serviceStr1);
	file.close();		
	std::string serviceStr2 = serviceStr1;
        string serviceStr3 = stringFindChar(serviceStr2, serviceStr2.length(), '/', true);
        int userYear = stoi(serviceStr3);
        serviceStr2 = stringFindChar(serviceStr1, serviceStr1.length()-serviceStr3.length()-1, '/',true);
	serviceStr3 ="";
	serviceStr3 +=serviceStr2[ serviceStr2.length() -2 ];
	serviceStr3 +=serviceStr2[ serviceStr2.length() -1 ] ;	
        int userMonth = stoi(serviceStr3);
        serviceStr3= stringFindChar(serviceStr1, 0, '\t', false);	
	serviceStr2 = stringFindChar(serviceStr1, serviceStr3.length()+1, '\t', false);
	ptr_Track->setName(serviceStr3);
	time_t temp = (time_t ) stoi( serviceStr2);
        ptr_Track->setDuration(temp);
        ptr_Track->setDate( userMonth, userYear);
        return ptr_Track;
    }
 /* +++++++++++++++++ */   
 int  getCounterLines(std::string &text)
{
	int counter =  howManyLines(text);
	if (counter == 0) counter = createList(text);
	counter = counter - 1;
	linesCount = counter;
	return  linesCount;
}    
/* +++++++++++++++++ */   
int getLinesCounter()
{
	return linesCount;
}
/* +++++++++++++++++ */   
private:
   /* Class TrackList items */
    std::string file_name = setFilename();
    int linesCount=0;
};     /*  Class TrackList end */
/* +++++++++++++++++ */  
/*  Class Commands begin */
class Commands
{
	   /* Class Commands items */
	std::vector <string>  commands  = { "play","pause","exit","stop","next" };
/* +++++++++++++++++ */  
public:	
		 /* Class Commands functions */
int itemFromStr(std::string action)
    {
        int item;
        for (item = 0; item < commands.size(); item++)
            if (commands[item] == action) break;
        item++;
	    menu_num =item;
        return item;
    }
  /* +++++++++++++++++ */  
std::string parsingStrToLowerCase(std::string text)
{
    for_each(text.begin(), text.end(), [](char& c) {
        c = tolower(c);
        });
    return text;
}
/* +++++++++++++++++ */  
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
	action  = parsingStrToLowerCase(action);
        return  action;
}
    /* +++++++++++++++++ */  
       /* Class Commands items */
	int menu_num = 3;	
};      /*  Class Commands end */
/* +++++++++++++++++ */  
  /*  Class Player begin */
class Player
{	
	     /* Class Player items */
		TrackList *MyPlayer = new TrackList();
		Commands *Item = new Commands();
		int track_num = 0;
		int current_rec = 0;	
		enum status 
		{
			PLAY = 16,
			PAUSE = 32,
			STOP = 64,
		};	
	 /* Class Player functions */
/* +++++++++++++++++ */  	
	int getListItem(int maxLevel)
	{
		bool done = false;
		int num =0 ;
		do {				
		std::cout << "Please, choose the record number > ";
		std::cin >> num;
		done = (num > 0) && (num <= maxLevel + 1);	
		if (done )  { num--; done =false;}
		else 	done = true;
		} while (done);
			
		return num;
	}
/* +++++++++++++++++ */  	
public:
	void createTrackList()
	{		
		bool playAgain = true;
		bool done = true;
		std::string f_name = MyPlayer->getFilename();
	//	MyPlayer->showOne(std::cout ,  MyPlayer->loadOneRecord(MyPlayer->getFilename(),track_num));		
		do {
			  if (playAgain) track_num = (getListItem(MyPlayer->getCounterLines(f_name)));	
			  playAgain = false;		
		switch (Item->itemFromStr(Item->setCommnand()))
		{
		case 1: 	if  (current_rec  !=  PLAY ) current_rec = play(current_rec,track_num); 
				break;
		case 2: 	if  ( current_rec  != STOP ) current_rec =pause( current_rec, track_num);   
				break;
		case 3: 	done = false;
				break;
		case 4: 	if  ( current_rec  != STOP ) current_rec = xit(current_rec); playAgain = true ;
				break;
		case 5: 	current_rec =0; track_num=next(track_num); current_rec = play(current_rec,track_num);
				break;
		default: 	if  (current_rec !=  PLAY ) current_rec = play(current_rec,track_num); 
				break;
		};
			} while (done);
		
		delete MyPlayer;
		MyPlayer = nullptr;
		delete Item;
		Item = nullptr;		
	}
	/* +++++++++++++++++ */  
	 int pause( int& status ,int rec)
	{		
		int local_status = status ;
		if ( status == PAUSE  )
			{
				std::cout << "Playback starts. Track is #" << 1 + rec << std::endl;
				 local_status  =   PLAY;							
			}
			else {
				std::cout << "Playback paused. Track is #" << 1+ rec << std::endl;				
				 local_status =   PAUSE;								
			}	
		return  local_status ;
	}
	/* +++++++++++++++++ */  
	int  xit( int& status)
	{	
		if ( status != STOP  ) {
			std::cout << "Player stops. \n";			
		}
		return STOP;
	}
	/* +++++++++++++++++ */  
	int play(int& status ,int rec)
	{
		if  ( status !=  PLAY ) {
		std::cout << "Playback starts. Track is #" <<1+ rec<< std::endl;
		MyPlayer->showOne(std::cout ,  MyPlayer->loadOneRecord(MyPlayer->getFilename(),rec));			
		}
		return  PLAY;
	}
	/* +++++++++++++++++ */  
	int  next(int rec)
	{
		int max =  MyPlayer->getLinesCounter();
		int local_rec = rec +1;
		if (local_rec > max) local_rec = 0;		
		return  local_rec;
	}
};
  /*  Class Player end */
/* +++++++++++++++++ */  
/* main function */
int main()
{
	setlocale(LC_ALL, "En-gb");
	Player *_Player = new Player();
	_Player ->  createTrackList();
	delete _Player;
	_Player = nullptr;   
	return 0;
}