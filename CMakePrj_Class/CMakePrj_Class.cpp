// CMakePrj_Class.cpp: определяет точку входа для приложения.
//
#define  _CRT_SECURE_NO_WARNINGS
#include "CMakePrj_Class.h"
#include "Player.h"
#include "Track.h"



const std::string file_ = "audiotracks.txt";
int main()
{
    setlocale(LC_ALL, "Russian");

    Player MyPlayer(file_, false);// При значении второго параметра true выводится список треков
    
    MyPlayer.show();// Этот метод не выводит список треков! Почему?
    system("pause");
    return 0;
}
