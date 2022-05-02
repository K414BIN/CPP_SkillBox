#include <map>
#include <string>
#include <iostream>

//
using namespace std;
//
typedef map<char,int,less<>> myMap;
//
tuple<string, string > splitedStrings(const string& str);
bool abnormalSymbolsAreNotIn(const string& str);
void show(myMap& inputMap);
myMap  Add(myMap& inputMap, const string str);
int stringFindChar(string str, int pos, char ch);
bool checkWords(int x, int y);
//
int main()
{
	myMap myDictionary;
	setlocale(LC_ALL, "en-US");
	string temp = "Crossbow";
	cout << "\tWelcome User to anagram contest!\nUse English words only! Let us begin then! " << endl;
	int j;

	do {
		cout <<"Enter two words via space to compare : \n";
		getline(cin, temp);
		j = stringFindChar(temp, 0, ' ');
	} while (j == temp.length());

		bool done = abnormalSymbolsAreNotIn(temp);
	if (done) {
		string word1;
		string word2;
		tie(word1, word2) = splitedStrings(temp);
		bool compareLen = (word1.length() == word2.length());
		bool compareWord = (word2 != word1);
		if (compareLen) {
							if (compareWord){
							myDictionary.clear();
							myDictionary = Add(myDictionary, word1);
							int comp2 = myDictionary.size();
							myDictionary = Add(myDictionary, word2);
							int comp1 = myDictionary.size();
							if (checkWords(comp1,comp2)) 
									 cout << "\nYes, the words can be anagrams! ";
								else cout << "\nNo, the words cannot be anagrams!";
							}
							else cout << "The words are the same !\n";
		}
		else cout << "The words cannot be anagrams - they have a different number of letters!\n";
	}
	else cout <<"It is not English word!"<< endl;
	
	cout  << endl;
//	show(myDictionary);
	system("pause");
	return 0;
}
//
bool abnormalSymbolsAreNotIn(const string& str) 
{
	const string match2 = " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::size_t  found = str.find_first_not_of(match2);
	if (found != std::string::npos) return false;
	return true;
}
//

myMap  Add(myMap &inputMap,const string str)
{
	for (int j = 0; j < str.length(); j++) 
    {
      	pair<char, int> item(str[j],  j);
		inputMap.insert(item);
	}
	return inputMap;
}
//
void show(myMap& Map)
{
	for (myMap::iterator it = Map.begin(); it != Map.end(); ++it) 
	{
		cout << it->first  << "  " << it->second;
		cout << endl;
	}
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
// my favorite tuple
tuple<string, string > splitedStrings(const string& str)
{
	string part1 = "";
	string part2 = "";
	int pos = stringFindChar(str, 0, ' ');
	for (int k = 0; k < str.length(); k++) {
		char temp = str[k];
		if (k < pos) part1 += temp;
		if (k > pos) part2 += temp;
	}
	tuple<string, string> result = { part1,part2 };
	return result;
}
//
bool checkWords(int x , int y)
{
	return (x == y);
}
// End of file.