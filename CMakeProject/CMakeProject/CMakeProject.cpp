#include <array>
#include <string>
#include <iostream>
#include <fstream>
#include "CMakeProject.h"
#include "ram.h"
#include "kbd.h"
#include "gpu.h"
#include "disk.h"
#include "cpu.h"

typedef  std::array<int, 8> Tarray;

//
std::string parsingStrToLowerCase(const std::string text)
{
	std::string  result = "";
	for (std::size_t i = 0; i < text.length(); ++i)
	result += tolower(text[i]);
	return result;
}
//
int caseOfItems(const std::string text, std::array<std::string, 6 > commands)
{
	int result = 0;
	std::size_t len = sizeof(commands) / sizeof(commands[0]);
	for (std::size_t j = 0; j < len; j++)
		if (text == commands[j])	result = j;
	return result;
}
//
int main()
{
	std::string inputStr;
	bool cycle = true;
	do {
		std::cout << "\t\tHello, user!\nPlease, enter action word to proceed: " << std::endl;
		std::cin.sync();
		std::cin >> inputStr;
		inputStr = parsingStrToLowerCase(inputStr);
		int answer = caseOfItems(inputStr, comands);
		Tarray UserArr = { 0 };
		switch (answer)
		{

		case 1:	UserArr = read(write(inputDigits(UserArr)));
	   			break;
		case 2:	VGAOutput(read(write(UserArr)));
				break;
		case 3:	UserArr = read(write(load(file)));
				break;
		case 4: save(file,UserArr);
				break;
		case 5:	compute(read(write(UserArr)));
				break;
		default: cycle = false; 
				 break;
		}
	} while (cycle);

	system("pause");
	return 0;
}
