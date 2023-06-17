#pragma once
#include "Play_Viewports.hpp"
#include "Asset.hpp"
#include <conio.h>
#include <iostream>

using namespace asset;

Scene titleScene(40, 20);
UI gameName(14, 5, "김석범 게임");
UI menu1(13, 7, "1. 이어하기");
UI menu5(13, 9, "3. 게임설명");
UI menu2(13, 10, "4. 게임종료");
UI menu6(13, 8, "2. 처음부터");

void Title_Initialize()
{
	titleScene.Hierarchy.push_back(&gameName);
	titleScene.Hierarchy.push_back(&menu1);
	titleScene.Hierarchy.push_back(&menu2);
	titleScene.Hierarchy.push_back(&menu5);
	titleScene.Hierarchy.push_back(&menu6);
}

int selNum=1;

int PlayTitle()
{
	titleScene.Draw();
	gameName.Selected(bluegreen);

	switch (selNum)
	{
	case 1:
		menu1.Selected(yellow);
		break;
	case 2:
		menu6.Selected(yellow);
		break;
	case 3:
		menu5.Selected(yellow);
		break;
	case 4:
		menu2.Selected(yellow);
		break;
	}

	if (_kbhit())
	{
		char key_input = _getch();

		switch (key_input)
		{
		case Key_UP:
		case Key_LEFT:
			if (selNum > 1)
			{
				selNum--;
			}
			break;
		case Key_DOWN:
		case Key_RIGHT:
			if (selNum < titleScene.Hierarchy.size() - 1)
			{
				selNum++;
			}
			break;
		case Key_ENTER:
			if (selNum == 1)
			{
				system("cls");
				selNum = 1;
				return State_WormGame;
			}
			if (selNum == 2)
			{
				system("cls");
				selNum = 1;
				Dead();
				return State_WormGame;
			}
			else if (selNum == 3)
			{
				system("cls");
				selNum = 1;
				return State_Info;
			}
			else if (selNum == 4)
			{
				exit(1);
			}
			break;
		}

		key_input = NULL;
	}

	return State_GameTitle;
}
