#include <array>
#include <iostream>
#include <string>
#include <fstream>
#include "disk.h"

//
 std::array<int, 8>  load(const std::string inputStr)
{
     std::array<int, 8>   result = {0};
    int end = sizeof(result) / sizeof(result[0]);
    std::ifstream file;
    file.open(inputStr);
    if (!file.is_open()) {
        std::cout << "Error open input file " << inputStr << " !\n";
        return result;
    }
    int k = 0;
    do {
        file >> result[k];
        k++;
    } while (k!=end);
    file.close();
    return result;
}
//
void save(const std::string _file,const  std::array<int, 8>  &inputArr )
{
    std::ofstream file(_file);
    if (!file.is_open()) {
        std::cout << "Error open output file!\n";
        return ;
    }
    int len = sizeof(inputArr) / sizeof(inputArr[0]);
    
  // Сохранение текущего состояния вывода символов
    auto* coutbuf = std::cout.rdbuf();
    //Перенаправление вывода символов включено - это файл
    std::cout.rdbuf(file.rdbuf());
    // Вывод информации
    for (size_t j = 0; j < len; j++ )
                std::cout << "\t" << inputArr[j];
    std::cout << "\n";
    
    //Перенаправление вывода символов отменено
    std::cout.rdbuf(coutbuf);
    //Закрываю файл
    file.close();
 }