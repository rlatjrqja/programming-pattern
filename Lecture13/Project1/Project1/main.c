#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
#include "screen.h"
#include "Util.h"
#define MAX_SNAKE_LENGTH 1400

int Initialize();
int Release();
void CheckError(int e);
int drawBuffer(int deltatime);

int GameState = 1;

struct GameObject
{
	int posX;
	int posY;
	int isActive;
};
struct GameObject snakeSkin[MAX_SNAKE_LENGTH];
struct GameObject Apple;

int main()
{

	CheckError(Initialize());

	unsigned long time_end = GetTickCount();
	unsigned long time = GetTickCount();

	while (GameState)
	{
		time = GetTickCount() - time_end;
		time_end = GetTickCount();

		if (time < 33)
		{
			Sleep(33-time);
		}

		drawBuffer(time);
	}

	Release();

	return 0;
}
void InitApple()
{
	srand(time);
	Apple.posX = rand() % 70;
	Apple.posY = rand() % 20;
}
void InitSnake()
{
	int i = 0;
	while (i < MAX_SNAKE_LENGTH)
	{
		snakeSkin[i].posX = 35-i;
		snakeSkin[i].posY = 10;
		snakeSkin[i].isActive = 0;
		i++;
	}
}

int Initialize()
{
	GameState = 1;

	setScreenSize(70, 20);
	SetCursorVisibleisty(0);
	SetColor(0b1111, 0b1000);

	//GameObject Init
	InitApple();
	
	ClearBuffer();
	
	return 0;
}

int drawBuffer(time)
{
	setCursorPos(0, 0);

	SetColor(0b1111, 0b1000);
	printf("%s", ScreenBuffer);

	SetCursorPos(Apple.posX, Apple.posY);
	SetColor(0b0000, 0b0010);
	printf("0");

	SetColor(0b0000, 0b1111);
	if (time != 0)
	{
		printf("time : %d \nfps : %d", time, 1000 / time);
	}

	return 0;
}

int Release()
{
	printf("프로그래밍 패턴 / C 프로그래밍 기초\n");

	return 0;
}