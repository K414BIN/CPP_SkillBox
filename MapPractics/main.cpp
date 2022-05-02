#include <map>
#include <string>
#include <iostream>
//
using namespace std;
//
typedef map<string, int,less<>> myMap;
//
myMap Del(myMap& inputMap);
bool abnormalSymbolsAreNotIn(const string& str);
void show(myMap& inputMap);
myMap Add(myMap& inputMap, pair <string, int> val);
//
int main()
{
	myMap myDictionary;
	setlocale(LC_ALL, "Russian");
	cout.imbue(locale(".1251"));
	cin.imbue(locale(".866"));
	string temp;
	int j = 1;
	bool done = true;
	
		cout << "\tДобро пожаловать в нашу поликлиннику #2!\nЗаписывайтесь в очередь самостоятельно! Подходите в регистратуру по слову \"Next\". " << endl;
		cout << "При наступлении перерыва на обед (вводится слово \"lunch\") прием прекращается!\n";
		cout << "Посмотреть сколько человек в очереди можно, высунув в окошко голову (вводится слово \"head\").\n";
	do {
		getline(cin, temp);

		bool check = abnormalSymbolsAreNotIn(temp);

		if ("head" == temp)
		{
			show(myDictionary);
			check = false;
		}
		
		done = ("lunch" != temp);

		if (done) {

					if ("Next" != temp ) {
											if (check) Add(myDictionary, make_pair(temp, j++));
											else cout << "\nНеправильно указана фамилия!\n";
					}
					else
					{
											if (!myDictionary.empty()) Del(myDictionary);
											else  cout << "\nОчередь пуста!!!\n";

					}
		}

	} while (done);

	cout << endl;
	show(myDictionary);
	cout  << endl;

	system("pause");
	return 0;
}
//
bool abnormalSymbolsAreNotIn(const string& str) 
{
	const string match2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::size_t  found = str.find_first_not_of(match2);
	if (found != std::string::npos) return false;
	return true;
}
//
myMap Del(myMap& inputMap)
{
	inputMap.erase(inputMap.begin());
	return inputMap;
}
//
myMap  Add(myMap &inputMap, pair <string, int> val)
{
	 inputMap.insert(val);
	 return inputMap;
}
//
void show(myMap& inputMap)
{
	for (myMap::iterator it = inputMap.begin(); it != inputMap.end(); ++it)
	{
		cout << it->first;
		cout << " , ";
	}
}
// End of file.