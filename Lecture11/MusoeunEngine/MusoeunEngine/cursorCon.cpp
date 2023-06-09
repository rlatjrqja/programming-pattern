#include "cursorCon.hpp"
#include <windows.h>


namespace cursor
{
	void gotoxy(int x, int y) {
		//x, y 좌표 설정
		COORD pos = { x,y };
		//커서 이동
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	void SetCursorState(bool state)
	{
		CONSOLE_CURSOR_INFO consoleCursorInfo;
		consoleCursorInfo.bVisible = state;
		consoleCursorInfo.dwSize = 1;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);
	}

	void SetColor(unsigned short backgroundColor, unsigned short TextColor)
	{
		unsigned short color = TextColor;
		color = color + (backgroundColor << 4);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}
}