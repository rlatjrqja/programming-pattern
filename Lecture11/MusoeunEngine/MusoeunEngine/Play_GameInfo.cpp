#pragma once
#include "Play_Viewports.hpp"
#include "Asset.hpp"
#include <conio.h>
#include <iostream>

using namespace std;

int PlayInfo()
{
	cout << "                           ������ ���� �������Դϴ�." << endl << endl << endl << endl;
	cout << "w,a,s,d,esc,enter 6���� Ű�� ���� �����մϴ�." << endl << endl << endl;
	cout << "                * UI ���� *" << endl << endl;
	cout << "w , a : �� �Ǵ� ���� �޴��� �����մϴ�." << endl;
	cout << "s , d : �Ʒ� �Ǵ� ���� �޴��� �����մϴ�." << endl << endl;
	cout << "�̾��ϱ�: ���� ���� �������� ������ �̾ �����մϴ�." << endl;
	cout << "enter : ���õ� �޴��� �̵��մϴ�." << endl;
	cout << "ó������: �������� ���̰� 3�� ó�� ���·� �����մϴ�." << endl << endl << endl;
	cout << "                * ���� ���� *" << endl << endl;
	cout << "w : ĳ������ ���� ������ �� �������� �ٲߴϴ�." << endl;
	cout << "a : ĳ������ ���� ������ ���� �������� �ٲߴϴ�." << endl;
	cout << "s : ĳ������ ���� ������ �Ʒ� �������� �ٲߴϴ�." << endl;
	cout << "d : ĳ������ ���� ������ ������ �������� �ٲߴϴ�." << endl;
	cout << "esc : ������ �����մϴ�." << endl << endl << endl;
	cout << ANSI_COLOR_YELLOW"�޴� ȭ������ �������� esc�� ��������" 
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