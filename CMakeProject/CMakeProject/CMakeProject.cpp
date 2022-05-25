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
	std::array<int, 8> UserArr = { 0 };
	std::string inputStr;
	bool cycle = true;
	std::cout << "\t\tHello, user!\n";
	std::cout << "Let's see how a computer works today. For this you need to enter the following commands:\n";
	std::cout << "display - to show result. \n";
	std::cout << "input - for enter values. \n";
	std::cout << "sum - for calculate values. \n";
	std::cout << "save - to save values to disk. \n";
	std::cout << "load - to load values from disk. \n";
	std::cout << "exit - to exit simulation. \n";
	do {
		//Симуляция работы компьютера
		std::cout << "Please, enter action word to proceed: " << std::endl;
		std::cin.sync();
		std::cin >> inputStr;
		inputStr = parsingStrToLowerCase(inputStr);
		int answer = caseOfItems(inputStr, comands);
		
		switch (answer)
		{

		case 1:	UserArr = read(write(inputDigits(UserArr)));
	   			break;
		case 2:	UserArr = write(UserArr);// push to PC RAM - simulation
				UserArr = read(UserArr);// pop from PC RAM - simulation
				VGAOutput(UserArr); // output to screen PC - simulation
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
