#include <iostream>
using namespace std;
#include <windows.h>

void Setcolor(int code)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, code);
}

void Color()
{
    Setcolor(0 << 10 | 0 << 4 | 11);
    system("cls");
    cout <<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout <<"@@ ______________________________________________________________________________|@@\n";
    cout <<"@@|                  _______     _______                  _______                |@@\n";
    cout <<"@@|                 |       |   |       |    |           |       |               |@@\n";
    cout <<"@@|                 |_______|   |_______|    |            _______|               |@@\n";
    cout <<"@@|                 |           |       |    |           |                       |@@\n";
    cout <<"@@|                 |           |_______|    |_______    |_______                |@@\n";
    cout <<"@@|                                                                              |@@\n";
    cout <<"@@|         ___   ___     ___   ___     ___   ___     ___   ___         ___      |@@\n";
    cout <<"@@|       _|_  | |___|   |___| |   |   |     |   |   |___  |   |   |     |       |@@\n";
    cout <<"@@|        |___| |___|   |   | |   |   |___  |___|    ___| |___|   |___  |       |@@\n";
    cout <<"@@|                                                                              |@@\n";
    cout <<"@@|                                                                              |@@\n";
    cout <<"@@|    1. Ho va ten: Nguyen Viet Nhat Long                                       |@@\n";
    cout <<"@@|            MSSV: 102210260                    GV Huong Dan: MAI VAN HA       |@@\n";
    cout <<"@@|    2. Ho va ten: Le Trung Dong                                               |@@\n";
    cout <<"@@|            MSSV: 102210248                                                   |@@\n";
    cout <<"@@|                                                                              |@@\n";
    cout <<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    Setcolor(0 << 10 | 0 << 4 | 15);
    system("pause");
}