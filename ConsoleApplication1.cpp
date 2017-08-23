#include "stdafx.h"
#include <graphics.h>
#include <time.h>
#include <conio.h>
#pragma comment(lib, "Winmm.lib")

#define Width 500
#define High 400

IMAGE img_bk, img_bd, img_bar_up, img_bar_down;
int bird_x, bird_y;
int bar_top_x, bar_top_y;
int bar_bottom_x, bar_bottom_y;

void startup() {
	initgraph(Width, High);

	loadimage(&img_bk, _T("F:\\C\\picture\\background.jpg"));
	loadimage(&img_bd, _T("F:\\C\\picture\\bird.jpg"));
	loadimage(&img_bar_up, _T("F:\\C\\picture\\bar_up.jpg"));
	loadimage(&img_bar_down, _T("F:\\C\\picture\\bar_down.jpg"));

	bird_x = Width / 5;
	bird_y = High / 2;

	srand((unsigned)time(NULL));

	bar_top_x = Width / 2;
	bar_top_y = 0 - rand() % 26 * 10;

	bar_bottom_x = bar_top_x;
	bar_bottom_y = bar_top_y + 400;

	BeginBatchDraw(); 

	mciSendString(_T("open F:\\C\\music\\background2.mp3 alias bkmusic"), NULL, 0, NULL);
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
}

void show() {
	putimage(0, 0, &img_bk);
	putimage(bar_top_x, bar_top_y, &img_bar_up);
	putimage(bar_bottom_x, bar_bottom_y, &img_bar_down);
	putimage(bird_x, bird_y, &img_bd);

	FlushBatchDraw();
	Sleep(50);
}

void updateWithoutInput() {
	if (bird_y < High - 4) bird_y += 2;
}

void updateWithInput() {
	MOUSEMSG m;
	if (MouseHit()) {
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) bird_y -= 60;
	}
	CHAR input;
	if (_kbhit()) {
		input = _getch();
		if (input = ' ' && bird_y > 20) bird_y -= 60;
	}
}

int main() {
	startup();

	for (;;) {
		show();
		updateWithoutInput();
		updateWithInput();
	}
	EndBatchDraw();
	closegraph();
	return 0;
}