#include <Windows.h>
#include <conio.h>
#include "Play_Viewports.hpp"
//#include "cursorCon.hpp"
#include "Asset.hpp"

using namespace asset;

Scene gameOverScene(40, 20);
UI gameOverText(13, 5, "���ӿ���");
UI menu3(13, 7, "1. �ٽ��ϱ�");
UI menu4(13, 8, "2. �׸��ϱ�");

char key_input2;

void gameOver_Initialize()
{
	gameOverScene.Hierarchy.push_back(&gameOverText);
	gameOverScene.Hierarchy.push_back(&menu3);
	gameOverScene.Hierarchy.push_back(&menu4);
}

int PlayGameOver()
{
	gameOverScene.Draw();

	if (_kbhit())
	{
		key_input2 = _getch();

		switch (key_input2)
		{
		case Key_UP://����ϱ�
			return 2;

		case Key_DOWN://�׸��ϱ�
			return 1;

		default:
			return 0;
		}
	}

	return 0;
}