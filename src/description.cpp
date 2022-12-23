#pragma once

#include <iostream>
#include "description.h"
#include"ChessBoard.h"




void description()
{
	WinBGI &win = WinBGI::instance();

	win.settextstyle(SANSSERIF_FONT, HORIZ_DIR, 4);  // 폰트설정
	win.outtextxy(170, 50, "Chess game Description");   // 문자열출력

	int offset = 150;
	int gap = 50;

	// vertical lines 
	for (int y = 0; y < 10; y++) {
		win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
	}

	for (int x = 0; x < 9; x++) {
		win.line(x * gap + offset, offset, x * gap + offset, offset + 9 * gap);
	}
	
	int symbol_offset = gap / 3;
	int circle_gap = gap / 2;
	int str_gap = gap / 5;


	char pieces_b[9][3] = { "R", "N", "B", "K", "Q", "B", "N", "R", "P" };


	for (int i = 0; i < 8; i++)
	{
		win.setcolor(COLOR_BLUE); // 라인 컬러
		win.settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
		win.outtextxy(offset + 15 + gap * i, offset + 14, pieces_b[i]);
		win.circle(offset + circle_gap + gap * i, offset + circle_gap, 22);


		win.outtextxy(offset + 15 + gap * i, offset + 14 + gap, pieces_b[8]);
		win.setcolor(COLOR_BLUE); // 라인 컬러
		win.circle(offset + circle_gap + gap * i, offset + circle_gap + gap, 22);

	}


	char pieces_w[9][3] = { "R", "N", "B", "K", "Q", "B", "N", "R", "P" };


	for (int i = 0; i < 8; i++)
	{
		win.setcolor(COLOR_WHITE); // 라인 컬러
		win.settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
		win.outtextxy(offset + 15 + gap * i, offset + 14 + gap * 8, pieces_w[i]);
		win.circle(offset + circle_gap + gap * i, offset + circle_gap + gap * 7, 22);


		win.outtextxy(offset + 15 + gap * i, offset + 14 + gap * 7, pieces_w[8]);
		win.circle(offset + circle_gap + gap * i, offset + circle_gap + gap * 8, 22);
	}

	win.outtextxy(145, 345, "enter any key for the next stage");

	while (1) {
		if (win.kbhit()) {                     // 키보드 입력여부 
			char key = (char)win.getch();         // 입력이 있는 경우 호출
			std::cout << key << std::endl; // 입력값 확인
			win.cleardevice(); // clear screen      // 화면을 지움
			break;
		}
		win.delay(100);                       // 100ms를 멈춤   
	}
	

	win.settextstyle(SANSSERIF_FONT, HORIZ_DIR, 3);  // 폰트설정
	win.setcolor(COLOR_BLUE);
	win.outtextxy(60, 0, "Welcome to Chess Game Developed by SeongYong");

	win.settextstyle(SANSSERIF_FONT, HORIZ_DIR, 1);  // 폰트설정
	win.setcolor(COLOR_WHITE);
	win.outtextxy(0, 50, "Keys to sysmbols used ");
	win.outtextxy(0, 75, "wP = White pawn &  bP = Black pawn");
	win.outtextxy(0, 100, "wN = White Knight & bN = Black Knight");
	win.outtextxy(0, 125, "wB = White Bishop & bB = Black Bishop");
	win.outtextxy(0, 150, "wR = White Rook & bR = Black Rook");
	win.outtextxy(0, 175, "wQ = White Queen & bQ = Black Queen");
	win.outtextxy(0, 200, "wK = White King & bK =Black King");
	win.outtextxy(0, 225, "Rule for move is :");
	win.outtextxy(0, 250, "Move by selecting row & column to another valid location using row & column");

	win.outtextxy(230, 345, "Enter any key for play");

	while (1) {
		if (win.kbhit()) {                     // 키보드 입력여부 
			char key = (char)win.getch();         // 입력이 있는 경우 호출
			std::cout << key << std::endl; // 입력값 확인
			win.cleardevice(); // clear screen      // 화면을 지움
			break;
		}
		win.delay(100);                       // 100ms를 멈춤   
	}
}





