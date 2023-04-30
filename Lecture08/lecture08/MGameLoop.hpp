#pragma once //#define _IS_THIS_HEADER_INCLUDE
#include <Windows.h>

#define Key_ESC 27
#define Key_LEFT 'a'
#define Key_RIGHT 'd'
#define Key_ENTER 13

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"

namespace MuSoeun
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

	class MGameLoop
	{
	public:
		MGameLoop() {}
		~MGameLoop(){}

		bool isGameRunnning = true;//프로그램 실행시 계속 실행 됨
		bool isGamePause = false;//ESC 눌렀을 때 게임이 정지된 상태
		char BeforeKey;//Pause용 이전키 기억 변수

		void Initialize()
		{
			SetCursorState(false);

			gotoxy(3, 18);
			std::cout << "게임 초기화중" << std::endl;
			isGameRunnning = true;
			gotoxy(3, 19);
			std::cout << "게임 초기화끝" << std::endl;
		}
		void Release()
		{
			gotoxy(3, 22);
			std::cout << "게임 릴리즈" << std::endl;
		}
		void Update()
		{
			gotoxy(3, 20);
			std::cout << ANSI_COLOR_RESET"게임 실행중" << std::endl;
			
			if (_kbhit())
			{
				KeyEvent(_getch());
			}
		}
		void Pause()
		{
			gotoxy(10, 10);
			std::cout << "게임을 종료합니까?" << std::endl;
			gotoxy(10, 11);
			std::cout << "YES / NO" << std::endl;
		}
		void Render()
		{
			gotoxy(5, 5);
		}

		void Run()
		{
			Initialize();

			while (isGameRunnning)
			{
				while (!isGamePause)
				{
					Update();
				}
				KeyEvent(_getch());
			}
			Release();
		}

		void KeyEvent(char KeyInput)
		{
			if (!isGamePause)//게임이 정지 상태가 아닐 때
			{
				switch (KeyInput)
				{
				case Key_ESC:
					isGamePause = true;// esc 누르면 게임 정지
					system("cls");
					Pause();
					break;
				case Key_LEFT:
					Render();
					std::cout << ANSI_COLOR_RED"왼쪽 눌림  " << std::endl;
					break;
				case Key_RIGHT:
					Render();
					std::cout << ANSI_COLOR_BLUE"오른쪽 눌림" << std::endl;
					break;
				default:
					isGameRunnning = true;
					break;
				}
			}
			else//게임이 정지 상태일 때
			{
				switch (KeyInput)
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
				case Key_ENTER:
					if (BeforeKey == Key_LEFT)//YES 선택
					{
						isGamePause = false;
						isGameRunnning = false;
					}
					else if (BeforeKey == Key_RIGHT)//NO 선택
					{
						isGamePause = false;
					}
					system("cls");
					break;
				}
			}
			BeforeKey = KeyInput;
		}
	};
}