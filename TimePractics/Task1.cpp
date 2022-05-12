#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <thread>
#include <ctime>
#include <map>
#include <string>
#include <iomanip>

static bool s_Finished = false;
typedef  std::map <std::string, int > forecastMap;

void DoWork(forecastMap inputMap)
{
    using namespace std::literals::chrono_literals;
    std::cout << "Started thread ID " << std::this_thread::get_id() << " at ";
    std::time_t a = std::time(nullptr);
    std::tm* localTimeStart = std::localtime(&a);
    std::cout << asctime(localTimeStart) << std::endl;
    std::cout << "Press enter to stop broadcasting...\n";
    while (!s_Finished)
    {
        for (auto& item : inputMap)
        {
            item.second++;
            std::cout << "Today in " << item.first << "  " << item.second << " degrees\n";
        }
        std::this_thread::sleep_for(1s);
    }
}
// thread is new chapter of C++
int main()
{
    setlocale(LC_ALL, "rus");
    std::string inStr = "";

    forecastMap city = {
        {"Moscow",13},
        {"Saint-Peterburg",11},
        {"Kazan",12},
        {"Saratov",10}
    };
    std::cout << "Type in below word \"begin\" to start broadcast: \n";
    std::getline(std::cin, inStr);

    if (inStr == "begin") {

        std::time_t a = std::time(nullptr);
        std::thread thread(DoWork, city);
        std::cin.get();
        s_Finished = true;
        thread.join();

        std::time_t b = std::time(nullptr);
        std::tm* localTimeEnd = std::localtime(&b);
        std::cout << "Finished at ";
        std::cout << asctime(localTimeEnd) << std::endl;

        double differnt = std::difftime(b, a);

        std::cout << "Elapsed time = " << differnt << " sec" << std::endl;
    }
    return 0;
}