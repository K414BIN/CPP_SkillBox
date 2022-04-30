#include <map>
#include <string>
#include <iostream>

using namespace std;

/*		define funcs start		*/
map <int, string> harvest(int j);
void showAll(map <int, string> myMap);
int over();
/*		define funcs end		*/
//
int over()
{
	std::map  <string, string> myDictionary;
	int k = 1;
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
	return 0;
}

int main()
{
	int j = 1;
	map <int, string> myMap = harvest(j);
	showAll(myMap);
	cout << endl;
	over();
	system("pause");

	return 0;
}

//
map <int, string> harvest(int j)
{
	const int end = 12000;

	map <int, string> quene;

	for (int i = 0; i < end; i++) {

		string surname;

		do {
			cout << "Please, enter your surname: ";
			cin >> surname;
		} while (surname.length() < 1);
		int answer;

		pair <int, string> visitor(j, surname);
		quene.insert(visitor);
		j = j + 1;

		cout << "Do you want to add another man [1 - yes /  0 - no]: ";
		cin >> answer;
		if (answer == 0) i = end;
	}
	return quene;
}
//
void showAll(map <int, string> myMap)
{
	for (auto item : myMap)
	{
		cout << item.first << " - " << item.second << endl;
	}
}
// End of file.