#pragma once

char ScreenBuffer[65536];
int screenWidth = 70;
int screenHeight = 20;

void setCursorPos(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetColor(unsigned short backgroundColor, unsigned short TextColor)
{
	unsigned short color = TextColor;
	color = color + (backgroundColor <<4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ClearBuffer()
{
	int y = 0;
	while (y < screenHeight + 2)
	{
		int x = 0;
		while (x < screenWidth + 2)
		{
			if (y == 0 || y == screenHeight + 1)
				ScreenBuffer[x + (y * screenWidth + 3)] = '-';
			else
			{
				if (x == 0 || x == screenWidth + 1)
					ScreenBuffer[x + (y * screenWidth + 3)] = 'I';
				else ScreenBuffer[x + (y * screenWidth + 3)] = ' ';
			}
			x++;
		}
		ScreenBuffer[x + (y * screenWidth + 3)] = '\n';
		y++;
	}
	ScreenBuffer[y * screenWidth + 3] = '\0';
}

int WriteBuffer(int x, int y, const char* str)
{
	int i = 0;
	while (i < strlen(str))
	{
		ScreenBuffer[x + (y * (screenWidth + 3))] = str[i];
		i++;
	}
	
	return 0;
}


//안쓰는 함수, 클리어 버퍼 + 셋 컬러 합쳤지만 성능 저하되는 하위 호환
void ClearMonitor(int screenWidth,int screenHeight, unsigned short backgroundColor, unsigned short TextColor)
{
	SetColor(backgroundColor, TextColor);

	int y = 0;
	while (y < screenHeight + 2)
	{
		int x = 0;
		while (x < screenWidth + 2)
		{
			if(y==0||y== screenHeight +1)
			printf("-");
			else
			{
				if (x == 0 || x == screenWidth + 1)
					printf("I");
				else printf(" ");
			}
			x++;
		}
		printf("\n");
		y++;
	}
}