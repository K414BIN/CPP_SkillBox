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

    Player MyPlayer(file_);
    MyPlayer.show();
    system("pause");
    return 0;
}
