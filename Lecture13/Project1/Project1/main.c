#include <stdio.h>
#include <Windows.h>
#include "screen.h"

int Initialize();
int Release();
void CheckError(int e);

int GameState=0;

int main()
{
	//SetTextBGColor(0b1001, 0b1000);

	//setCursorPos(0, 0);
	//CheckError


	int isGameRunning = 1;

	Initialize();

	while (isGameRunning)
	{

		isGameRunning = 0;
	}

	//Release();

	return 0;
}






void CheckError(int e)
{
	if (e == 1)
	{
		printf("[line:%d, %s]������ �߻��߽��ϴ�.\n", __LINE__, __func__);
		exit(1);
	}
}

int Initialize()
{
	GameState = 0;

	SetColor(0b1000, 0b1111);
	setCursorPos(0, 0);
	
	ClearBuffer();
	WriteBuffer(30,4,"test");
	printf("%s", ScreenBuffer);
	

	return 0;
}

int Release()
{
	printf("���α׷��� ���� / C ���α׷��� ����\n");

	return 0;
}