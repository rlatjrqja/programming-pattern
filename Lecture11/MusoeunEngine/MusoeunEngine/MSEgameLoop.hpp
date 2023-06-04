#include "Play_Viewports.hpp"
#include "cursorCon.hpp"

using namespace std;
using namespace cursor;

namespace Musoeun
{
	enum GameState
	{
		title = 1, isGameing, gameOver, pause
	};
	GameState gamestate;

	void Master_Initialize();

	void MGameLoop()
	{
		Master_Initialize();

		while (1)
		{
			gotoxy(0, 0);
			switch (gamestate)
			{
			case title:
				if (PlayTitle() == 2) gamestate = isGameing;
				break;
			case isGameing:
				if (PlayGame() == 1) gamestate = title;
				//if (PlayGame() == 3) gamestate = gameOver;
				//if (PlayGame() == 4) gamestate = pause;
				break;
			case gameOver:
				exit;
				//if (PlayGameOver() == 1) gamestate = title;
				//if (PlayGameOver() == 2) gamestate = isGameing;
				break;
			case pause:
				break;
			}
			Sleep(100);
		}
	};


	void Master_Initialize()
	{
		gamestate = title;
		SetColor(0b1000, 0b1111);

		Title_Initialize();
		WormGame_Initialize();
		gameOver_Initialize();
	}
}
