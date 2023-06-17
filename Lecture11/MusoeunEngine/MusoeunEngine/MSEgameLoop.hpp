#pragma once
#include "Play_Viewports.hpp"
#include "cursorCon.hpp"
#include <Windows.h>

using namespace std;
using namespace cursor;

namespace Musoeun
{
	int gameState = State_GameTitle;

	void Master_Initialize();

	void MGameLoop()
	{
		Master_Initialize();

		while (1)
		{
			gotoxy(0, 0);

			switch (gameState)
			{
			case State_GameTitle:
				gameState = PlayTitle();
				break;
			case State_WormGame:
				gameState = PlayGame();
				break;
			case State_GameOver:
				gameState = PlayGameOver();
				break;
			case State_Pause:
				gameState = PlayPause();
				break;
			case State_Info:
				gameState = PlayInfo();
				break;
			}
			Sleep(100);
		}
	};

	void Master_Initialize()
	{
		SetCursorState(false);

		Title_Initialize();
		WormGame_Initialize();
		gameOver_Initialize();
	}
}
