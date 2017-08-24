// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <graphics.h>
#include <conio.h>
#define Width 320
#define High 320
#define Len 32
#define N Width/Len

int isBlock[N][N];
int man_x, man_y;
IMAGE img_block, img_man;
int move_left, move_right, move_up, move_down;

void startup() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == 0 || i == N - 1 || j == 0 || j == N - 1)
				isBlock[i][j] = 1;
			else
				isBlock[i][j] = 0;
		}
	}

	man_x = Width / 2; 
	man_y = High / 2;

	move_left = 0;
	move_right = 0;
	move_up = 0;
	move_down = 0;
}

void show() {

	loadimage(&img_block, _T("F:\\C\\picture\\block3.jpg"));
	loadimage(&img_man, _T("F:\\C\\picture\\walk.jpg"));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (isBlock[i][j])
				putimage(j * Len, i * Len, &img_block);
		}
	}

	FlushBatchDraw();
}

void updateWidthoutInput() {
	
}
void updateWithInput() {
	CHAR input;
	if (_kbhit()) {
		input = _getch();
		if (input == 'a' && man_x > Len) {
			clearrectangle(man_x, man_y, man_x + Len, man_y + Len);
			man_x -= 10;
			putimage(man_x, man_y, Len, Len, &img_man, move_left * Len, 1 * Len);
			move_left++;
			if (move_left == 3) move_left = 0;
		}
		else if (input == 'd' && man_x < Width - 2 * Len) {
			clearrectangle(man_x, man_y, man_x + Len, man_y + Len);
			man_x += 10;
			putimage(man_x, man_y, Len, Len, &img_man, move_right * Len, 2 * Len);
			move_right++;
			if (move_right == 3) move_right = 0;
		}
		else if (input == 'w' && man_y > Len) {
			clearrectangle(man_x, man_y, man_x + Len, man_y + Len);
			man_y -= 10;
			putimage(man_x, man_y, Len, Len, &img_man, move_up * Len, 3 * Len);
			move_up++;
			if (move_up == 3) move_up = 0;
		}
		else if (input == 's' && man_y < High - 2 * Len) {
			clearrectangle(man_x, man_y, man_x + Len, man_y + Len);
			man_y += 10;
			putimage(man_x, man_y, Len, Len, &img_man, move_down * Len, 0 * Len);
			move_down++;
			if (move_down == 3) move_down = 0;
		}
	}
}

int main()
{
	initgraph(Width, High);
	setbkcolor(RGB(100, 200, 130));
	cleardevice();
	startup();
	BeginBatchDraw();
	while (1) {
		show();
		updateWithInput();
	}
	EndBatchDraw();
	_getch();
	closegraph();
    return 0;
}

