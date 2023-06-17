#pragma once
#include "Play_Viewports.hpp"
#include "Asset.hpp"
#include <conio.h>
#include <iostream>

using namespace std;

int PlayInfo()
{
	cout << "                           게임의 설명 페이지입니다." << endl << endl << endl << endl;
	cout << "w,a,s,d,esc,enter 6개의 키로 조작 가능합니다." << endl << endl << endl;
	cout << "                * UI 관련 *" << endl << endl;
	cout << "w , a : 위 또는 이전 메뉴를 선택합니다." << endl;
	cout << "s , d : 아래 또는 다음 메뉴를 선택합니다." << endl << endl;
	cout << "이어하기: 진행 도중 빠져나온 게임을 이어서 진행합니다." << endl;
	cout << "enter : 선택된 메뉴로 이동합니다." << endl;
	cout << "처음부터: 지렁이의 길이가 3인 처음 상태로 시작합니다." << endl << endl << endl;
	cout << "                * 게임 관련 *" << endl << endl;
	cout << "w : 캐릭터의 진행 방향을 위 방향으로 바꿉니다." << endl;
	cout << "a : 캐릭터의 진행 방향을 왼쪽 방향으로 바꿉니다." << endl;
	cout << "s : 캐릭터의 진행 방향을 아래 방향으로 바꿉니다." << endl;
	cout << "d : 캐릭터의 진행 방향을 오른쪽 방향으로 바꿉니다." << endl;
	cout << "esc : 게임을 정지합니다." << endl << endl << endl;
	cout << ANSI_COLOR_YELLOW"메뉴 화면으로 나가려면 esc를 누르세요" 
		ANSI_COLOR_RESET << endl << endl;

	if (_kbhit())
	{
		char key_input = _getch();

		if (key_input == Key_ESC)
		{
			system("cls");
			return State_GameTitle;
		}
	}

	return State_Info;
}