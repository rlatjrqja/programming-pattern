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
		//x, y ��ǥ ����
		COORD pos = { x,y };
		//Ŀ�� �̵�
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

		bool isGameRunnning = true;//���α׷� ����� ��� ���� ��
		bool isGamePause = false;//ESC ������ �� ������ ������ ����
		char BeforeKey;//Pause�� ����Ű ��� ����

		void Initialize()
		{
			SetCursorState(false);

			gotoxy(3, 18);
			std::cout << "���� �ʱ�ȭ��" << std::endl;
			isGameRunnning = true;
			gotoxy(3, 19);
			std::cout << "���� �ʱ�ȭ��" << std::endl;
		}
		void Release()
		{
			gotoxy(3, 22);
			std::cout << "���� ������" << std::endl;
		}
		void Update()
		{
			gotoxy(3, 20);
			std::cout << ANSI_COLOR_RESET"���� ������" << std::endl;
			
			if (_kbhit())
			{
				KeyEvent(_getch());
			}
		}
		void Pause()
		{
			gotoxy(10, 10);
			std::cout << "������ �����մϱ�?" << std::endl;
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
			if (!isGamePause)//������ ���� ���°� �ƴ� ��
			{
				switch (KeyInput)
				{
				case Key_ESC:
					isGamePause = true;// esc ������ ���� ����
					system("cls");
					Pause();
					break;
				case Key_LEFT:
					Render();
					std::cout << ANSI_COLOR_RED"���� ����  " << std::endl;
					break;
				case Key_RIGHT:
					Render();
					std::cout << ANSI_COLOR_BLUE"������ ����" << std::endl;
					break;
				default:
					isGameRunnning = true;
					break;
				}
			}
			else//������ ���� ������ ��
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
					if (BeforeKey == Key_LEFT)//YES ����
					{
						isGamePause = false;
						isGameRunnning = false;
					}
					else if (BeforeKey == Key_RIGHT)//NO ����
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