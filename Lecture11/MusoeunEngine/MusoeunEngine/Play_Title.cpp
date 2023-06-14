#include "Play_Viewports.hpp"
#include "Asset.hpp"
#include <conio.h>

using namespace asset;

Scene titleScene(40, 20);
UI gameName(13, 5, "김석범 게임");
UI menu1(13, 7, "1. 게임시작");
UI menu2(13, 8, "2. 게임종료");

char key_input;

void Title_Initialize()
{
	titleScene.Hierarchy.push_back(&gameName);
	titleScene.Hierarchy.push_back(&menu1);
	titleScene.Hierarchy.push_back(&menu2);
}

int PlayTitle()
{
	titleScene.Draw();

	if (_kbhit())
	{
		key_input = _getch();

		switch (key_input)
		{
		case Key_UP:
			return State_WormGame;
		case Key_DOWN:
			exit(1);
			return State_GameTitle;
		default:
			return State_GameTitle;
		}

		key_input = NULL;
	}

	return State_GameTitle;
}
