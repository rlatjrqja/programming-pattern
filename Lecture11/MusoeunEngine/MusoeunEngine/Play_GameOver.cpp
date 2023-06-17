#include <conio.h>
#include "Play_Viewports.hpp"
#include "Asset.hpp"

using namespace asset;

Scene gameOverScene(40, 20);
UI gameOverText(13,4, "--게임오버--");
UI menu3(15, 8, "다시하기");
UI menu4(15, 10, "그만하기");

void gameOver_Initialize()
{
	gameOverScene.Hierarchy.push_back(&gameOverText);
	gameOverScene.Hierarchy.push_back(&menu3);
	gameOverScene.Hierarchy.push_back(&menu4);
}

int selNum2=1;

int PlayGameOver()
{
	gameOverScene.Draw();

	gameOverText.Selected(red);

	if (_kbhit())
	{
		char key_input = _getch();

		switch (key_input)
		{
		case Key_UP:
		case Key_LEFT:
			selNum2 = 1;
			break;
		case Key_DOWN:
		case Key_RIGHT:
			selNum2 = 2;
			break;
		case Key_ENTER:
			if (selNum2 == 1)
			{
				return State_WormGame;
			}
			else if (selNum2 == 2)
			{
				return State_GameTitle;
			}
			break;
		}

		key_input = NULL;
	}

	switch (selNum2)
	{
	case 1:
		menu3.Selected(yellow);
		break;
	case 2:
		menu4.Selected(yellow);
		break;
	default:
		break;
	}

	return State_GameOver;
}