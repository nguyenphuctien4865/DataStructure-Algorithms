#pragma once
#include<iostream>
using namespace std;


COORD coord = { 0, 0 };
int num = 1;
void picture(){
	cout << "Your Number :" << num << endl;
	cout << "                        " << endl;
	cout << "       |  |  |          " << endl;
	cout << "    _~__~__~__~__       " << endl;
	cout << "   |             |__    " << endl;
	cout << "   |   COFFEE    |  |   " << endl;
	cout << "   |             |__|   " << endl;
	cout << "   |_____________|       " << endl;
	cout << "                        " << endl;
	num++;

}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/////////////////////////////////////////////////////////////////////////////////
void animation()
{
	for (int i = 45; i >= 1; i--)
	{
		Sleep(30);
		gotoxy(1, i);
		//clreol();
	}
	for (int i = 1; i <= 20; i++)
	{
		//clreol();
		Sleep(40);
		gotoxy(1, i);
	}
}

