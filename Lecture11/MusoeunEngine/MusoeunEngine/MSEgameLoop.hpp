#include "Play_Viewports.hpp"
#include "cursorCon.hpp"

using namespace std;
using namespace cursor;

namespace Musoeun
{
	int gameState;

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
				break;
			}
			Sleep(100);
		}
	};


	void Master_Initialize()
	{
		gameState = State_GameTitle;
		SetColor(0b1000, 0b1111);

		Title_Initialize();
		WormGame_Initialize();
		gameOver_Initialize();
	}
}
