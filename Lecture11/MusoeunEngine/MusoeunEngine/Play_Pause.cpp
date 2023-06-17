#include <iostream>
#include "Play_Viewports.hpp"
#include "cursorCon.hpp"
#include <conio.h>

using namespace cursor;

char LastKey = Key_LEFT;

int PlayPause()
{
	gotoxy(10, 10);
	std::cout << "게임을 종료합니까?" << std::endl;
	gotoxy(10, 11);
	std::cout << ANSI_COLOR_YELLOW"YES ";
	std::cout << ANSI_COLOR_RESET"/ NO" << std::endl;

	if (_kbhit())
	{
		char key_input = _getch();
		bool selLeft = true;

		switch (key_input)
		{
		case Key_UP:
		case Key_LEFT:
			selLeft = true;
			break;
		case Key_DOWN:
		case Key_RIGHT:
			selLeft = false;
			break;
		case Key_ENTER:
			if (LastKey == Key_LEFT)//YES 선택
			{
				system("cls");
				return State_GameTitle;
			}
			else if (LastKey == Key_RIGHT)//NO 선택
			{
				system("cls");
				return State_WormGame;
			}
			break;
		}

		LastKey = key_input;
	}

	switch (LastKey)
	{
	case Key_LEFT:
		gotoxy(10, 11);
		std::cout << ANSI_COLOR_YELLOW"YES ";
		std::cout << ANSI_COLOR_RESET"/ NO" << std::endl;
		break;
	case Key_RIGHT:
		gotoxy(10, 11);
		std::cout << ANSI_COLOR_RESET"YES /";
		std::cout << ANSI_COLOR_YELLOW" NO";
		std::cout << ANSI_COLOR_RESET << std::endl;
		break;
	default:
		break;
	}

	return State_Pause;
}