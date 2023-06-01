#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include "screen.h"
#include "Util.h"

int Initialize();
int Release();
void CheckError(int e);
int drawBuffer();

int GameState=0;

int main()
{
	int isGameRunning = 1;

	CheckError(Initialize());

	unsigned long time_end = GetTickCount();
	unsigned long time = GetTickCount();

	while (isGameRunning)
	{
		drawBuffer();

		time = GetTickCount() - time_end;
		time_end = GetTickCount();

		if (time < 30)
		{

			Sleep(30-time);
		}
		if (time != 0)
		{

			printf("time : %d \nfps : %d", time, 1000 / time);
		}

	}

	Release();

	return 0;
}

int Initialize()
{
	GameState = 0;

	setScreenSize(70, 20);
	SetColor(0b1000, 0b1111);
	
	ClearBuffer();
	WriteBuffer(30,4,"���� ����");
	WriteBuffer(30, 6, "1. ���ӽ���");
	WriteBuffer(30, 7, "2. ��������");
	

	return 0;
}

int drawBuffer()
{
	setCursorPos(0, 0);
	printf("%s", ScreenBuffer);

	return 0;
}

int Release()
{
	printf("���α׷��� ���� / C ���α׷��� ����\n");

	return 0;
}