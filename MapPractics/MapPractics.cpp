#include <map>
#include <string>
#include <iostream>

using namespace std;
int main()
{
    std::map  <string, string> myDictionary;
    myDictionary.insert(pair<string, string>("69-70-30", "Ivanov"));
    myDictionary.insert(pair<string, string>("69-70-31", "Petrov"));
    myDictionary.insert(pair<string, string>("69-70-32", "Petrova"));
    myDictionary.insert(pair<string, string>("69-70-30", "Ivanova"));
    myDictionary.insert(pair<string, string>("69-70-35", "Smirnoff"));
    myDictionary.insert(pair<string, string>("69-70-33", "Soloviev"));
    myDictionary.insert(pair<string, string>("69-70-34", "Vasiliev"));
    for (auto pair : myDictionary) {
        cout << pair.first << " " << pair.second << " \n";
    }
    std::cout << "\n";
    system("pause");
    return 0;
}
