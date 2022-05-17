#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
// version at 11:14 16 мая 2022 г.
using namespace std;

const int XXCentury = 1900;
const string file_ = "births.txt";
const string stopProc = "end";
const char symbol = '/';
const char space = ' ';

struct tDay
{
    time_t presentYear = calcYear();
    time_t presentMonth = calcMonth();
    time_t presentDay = calcDay();

private: time_t  calcYear()
{
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);
    return XXCentury + ltm->tm_year;
}

private: time_t  calcMonth()
{
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);
    return 1 + ltm->tm_mon;
}

private: time_t  calcDay()
{
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);
    return ltm->tm_mday;
}
};
//
int howManyLines(istream& file)
{
    file.seekg(0, file.beg);
    int i = 0;
    string line;
    while (getline(file, line))
    {
        i++;
    }
    return i;
}
//
int days(int year, int month)
{
    int days = 28;
    switch (month) {
    case 2:   days = 28; break;
    case 4:
    case 6:
    case 9:
    case 11:  days = 30; break;
    default: days = 31; break;
    }
    bool value = (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
    if (value && (month == 2)) days = 29;
    return days;
}
//
void saveIt(const string& str1, const string& str2)
{
    ofstream file_out(str1, std::ios::app);
    if (!file_out.is_open()) {
        cout << "\nError open output file!" << endl;
        return;
    }
    file_out << str2;
    file_out.close();
}
//
string fork(int inp)
{
    string text = (inp < 10 ? "0" + to_string(inp) : to_string(inp));
    return text;
}
//
string parsingStrToLowerCase(const string text)
{
    string  result = "";
    for (size_t i = 0; i < text.length(); ++i)
        result += tolower(text[i]);
    return result;
}
//
bool isItFinish(const string& str1, const string& str2)
{
    string temp = parsingStrToLowerCase(str1);
    int result = temp.compare(str2);
    if (result == 0) return false;
    else return true;
}
//
void fillBase(const time_t valYear)
{
    int userDay;
    int userMonth;
    int userYear;
    string temp = "";
    bool good = true;
    cout << "\tДобро пожаловать в Вашу записную книжку!\nЕсли хотите закончить работу с записной книжкой, то введите \"end\" на запросе имени друга для выхода.\n";
    do {

        cout << "Введите имя друга:";
        cin >> temp;
        good = isItFinish(temp, stopProc);

        if (good)
        {
            cout << "\nВведите день, месяц и год рождения." << endl;
            //      
            do {
                cout << "Год: ";
                cin >> userYear;
            } while (userYear > valYear || userYear < XXCentury);
            //
            do {
                cout << "Месяц: ";
                cin >> userMonth;
            } while (userMonth < 1 || userMonth > 12);
            //
            int compDays = days(userYear, userMonth);
            do {
                cout << "День: ";
                cin >> userDay;
            } while (userDay < 1 || userDay > compDays);
            //
            temp += space;
            temp += fork(userDay);
            temp += symbol;
            temp += fork(userMonth);
            temp += symbol;
            temp += to_string(userYear);
            temp += " \n";
            saveIt(file_, temp);
        }
    } while (good);
}
//
bool isIt(const string text, const time_t input, const char symbol)
{
    string result = "";
    int val = input;
    int n = val;
    for (size_t j = 0; j < text.length(); j++) if (text[j] == symbol) { n = j; break; }
    for (size_t i = n + 1; i < n + 3; i++) result += text[i];
    n = stoi(result);
    return (val == n);
}
//
int howOld(const string text, const time_t year)
{
    string name = "";
    int val = year;
    int counter = text.length() - 5;
    for (size_t j = counter; j < text.length(); j++)  name += text[j];
    counter = stoi(name);
    return val - counter;
}
//
string Bday(const string text)
{
    string name = "";
    for (size_t j = 0; j < text.length(); j++) {
        if (text[j] == space) break;
        name += text[j];
    }
    return name;
}
//
string  readBase(const string  fileName, int counter)
{
    ifstream file(fileName);
    if (!file.is_open()) {
        return    "\nError open input file!\n";
    }
    file.seekg(0, file.beg);
    string result;
    for (size_t i = 0; i != counter - 1; i++)	getline(file, result);
    getline(file, result);
    file.close();
    return result;
}
/* Main function */
int main() {

    setlocale(LC_ALL, "Russian");
    tDay ToDay;
    //
    ifstream file_in(file_);
    if (!file_in.is_open()) {
        ofstream file_out(file_, std::ios::app);
        if (!file_out.is_open()) {
            cout << "\nError open file!" << endl;
            return 2;
        }
    }

    int countLines = howManyLines(file_in);
    file_in.close();
    if (countLines > 0)
    {
        do {
            string name = readBase(file_, countLines);
            countLines--;
            bool who = isIt(name, ToDay.presentMonth, symbol) && isIt(name, ToDay.presentDay, space);
            int  n = howOld(name, ToDay.presentYear);
            if (who) {
                name = Bday(name);
                cout << "Ваш друг, " << name << ", отмечает сегодня свой " << n << " день рождение!\n";
            }
        } while (countLines);

    }
    else cout << "Ваша записная книжка пуста!\n";
    cout << "Хотите добавть новую запись ? [1 - да / 0 - нет]  ";
    cin >> countLines;
    if (countLines != 0) fillBase(ToDay.presentYear);
    return 0;
}
//End of file