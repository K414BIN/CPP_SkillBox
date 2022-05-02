#include <map>
#include <string>
#include <iostream>

using namespace std;

// this string is very helpfull !
typedef 	map  < string, string > myMap;

/*		define funcs start		*/
pair<string, string > splitedStrings(const string& str);
map  < string, string> harvest(myMap  &myDictionary, string text1, string text2);
void showAll(myMap &myMap);
bool abnormalSymbolsAreNotIn(const string& str);
int stringFindChar(string str, int pos, char ch);
map  < string, string>  overLoad();
string  showTwo(myMap& myMap, const string& text);
string  showOne(myMap& myMap, const string& text);
/*		define funcs end		*/

//
int main()
{
	string temp;
	pair < string, string > inputStrs;
	map  < string, string > myRelatedMap = overLoad();
	cout << "\t\t\tHello, user!\nWelcome to highintelligence phonebook! Please, input string below:  "<<endl;
	getline(cin, temp);
	cout  << endl;

	if (stringFindChar(temp, 0, ' ') != temp.length()) 
	{
		inputStrs = splitedStrings(temp);
		if (abnormalSymbolsAreNotIn(inputStrs.first)) myRelatedMap.insert(inputStrs);
		else cout << "Input error!" << endl;
	}
	else if (abnormalSymbolsAreNotIn(temp)) 
	{
		cout << showTwo(myRelatedMap, temp) << endl;
	}
	else
	{
		cout << showOne(myRelatedMap, temp) << endl;
	}
	
	cout << endl;
	showAll(myRelatedMap);
	system("pause");
	return 0;
}
//
bool abnormalSymbolsAreNotIn(const string& str) 
{
	const string match2 = "0123456789-";
	std::size_t  found = str.find_first_not_of(match2);
	if (found != std::string::npos) return false;
	return true;
}
//
map  < string, string >  overLoad()
{
	map  <string, string> myDictionary;

	myDictionary.insert(pair<string, string>("69-70-38", "Sidoroff"));
	myDictionary.insert(make_pair<string, string>("69-70-31", "Petrov"));
	myDictionary.insert(pair<string, string>("69-70-32", "Petrova"));
	myDictionary.insert(pair<string, string>("69-70-30", "Ivanov"));
	myDictionary.insert(pair<string, string>("69-70-35", "Smirnoff"));
	myDictionary.insert(pair<string, string>("69-70-34", "Vasiliev"));
	myDictionary.insert(pair<string, string>("69-70-33", "Vasiliev"));

	return myDictionary;
}
map  < string, string> harvest(myMap  &myDictionary, string text1, string text2)
{
	myDictionary.insert(pair<string, string>(text1, text2));
	return myDictionary;
}
//
string  showOne( myMap &myMap, const string& text)
{
	bool done = false;
	string result = "";
	for (map <string, string>::iterator it = myMap.begin(); it != myMap.end(); ++it)
	{
		if (it->second == text)
		{		
			done = true;
			result += it->first + "\n";
		}
	}
	if (done) return result;
	else return text + " was not found!";
}
//
string  showTwo(myMap &myMap, const string &text)
{
	map <string, string>::iterator it = myMap.find(text);
	if (it->first == text) return it->second;
	else  return text + " was not found!";
}
//
void showAll(myMap& myMap)
{
	for (auto item : myMap)
	{
		cout << item.first << " - " << item.second << endl;
	}
}
//
pair<string, string > splitedStrings(const string& str) 
{
	string part1 = "";
	string part2 = "";
	int pos = stringFindChar(str, 0, ' ');
	for (int k = 0; k < str.length(); k++) {
		char temp = str[k];
		if (k < pos) part1 += temp;
		if (k > pos) part2 += temp;
	}
	pair<string, string> result = { part1,part2 };
	return result;
}
//
int stringFindChar(string str, int pos, char ch)
{
	while (pos != str.length()) {
		if (str[pos] == ch) { break; }
		pos++;
	}
	return pos;
}
// End of file.