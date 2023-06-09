#pragma once

#define Key_ESC 27
#define Key_UP 'w'
#define Key_DOWN 's'
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

#define State_GameTitle 1
#define State_WormGame 2
#define State_GameOver 3
#define State_Pause 4
#define State_Info 5

//���𿵿�
int PlayTitle();
int PlayGame();
int PlayGameOver();
int PlayPause();
int PlayInfo();

void Title_Initialize();
void WormGame_Initialize();
void gameOver_Initialize();

void Dead();