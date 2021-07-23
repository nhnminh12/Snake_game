#include<iostream>
#include"kmin_console.h"
using namespace std;
#define ran 254
#define max 100
#define len 1
#define xuong 2
#define trai 3
#define phai 4
void khoitao();
void hienthi();
void dichuyen(int huong);
void sukien(int &huong);
void ve();
struct toado
{
	int x;
	int y;
};
toado conran[100];
int sodot = 5;
void khoitao()
{
	conran[0].x = 4;
	conran[1].x = 5;
	conran[2].x = 6;
	conran[0].y = conran[1].y = conran[2].y = 1;
}
void hienthi()
{
	for (int i = 0; i < sodot; i++)
	{
		gotoXY(conran[i].x, conran[i].y);
		cout << (char)ran;
	}
}
void dichuyen(int huong)
{
	for (int i = sodot - 1; i >= 1; i--)
	{
		conran[i] = conran[i - 1];
	}
	switch (huong)
	{
	case len:
		conran[0].y--;
		break;
	case xuong:
		conran[0].y++;
		break;
	case trai:
		conran[0].x--;
		break;
	case phai:
		conran[0].x++;
		break;
	}
}
void sukien(int &huong)
{
	int key = inputKey();
	if (key == KEY_UP)
	{
		huong = len;
	}
	else if (key == KEY_RIGHT)
	{
		huong = phai;
	}
	else if (key == KEY_DOWN)
	{
		huong = xuong;
	}
	else if (key == KEY_LEFT)
	{
		huong = trai;
	}
}

void main()
{
	/*system("cls");
	for (int i = 0; i < 256; i++)
	{
		cout << i << ": " << (char)i << endl;
	}*/
	khoitao();
	int x = 0, y = 0;
	int huong = trai;
	while (1)
	{
		clrscr();
		dichuyen(huong);
		sukien(huong);
		hienthi();
		Sleep(500);
	}
	

}