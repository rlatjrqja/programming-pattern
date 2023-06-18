#include "Play_Viewports.hpp"
#include "Asset.hpp"
#include <vector>
#include <conio.h>

//#include <Windows.h>
//#include <time.h>

#define ViewPortWwidth 80
#define ViewPortHeight 28
#define InitLen 3

using namespace asset;

enum Direction { UP, DOWN, LEFT, RIGHT };

void handleInput();
void update();

typedef struct {
    int x;
    int y;
} Position;

class SnakeBody :public Object {
public:

    char* Buffer;
    void Render(char* ScreenBuffer, int Viewport_width)
    {
        *ScreenBuffer = '*';
        Buffer = ScreenBuffer;
    }

    void Erase()
    {
        *Buffer = ' ';
    }
};

class SnakeHead :public Object {
public:
    int score;
    enum Direction direction;

    vector <SnakeBody*> snakeTails;

    void Render(char* ScreenBuffer, int Viewport_width)
    {
        switch (direction)
        {
        case UP:
            *ScreenBuffer = '^';
            break;
        case LEFT:
            *ScreenBuffer = '<';
            break;
        case RIGHT:
            *ScreenBuffer = '>';
            break;
        case DOWN:
            *ScreenBuffer = 'v';
            break;
        }
    }
};



class Food :public Object {
public:
    int eaten;
};

Scene gameScene(ViewPortWwidth, ViewPortHeight);
SnakeHead snakeHead;
Food food;
//UI Score(1, 28,"Score : 0");

int RN = State_WormGame;

void WormGame_Initialize()
{
    srand((unsigned int)time(NULL));

    //머리 초기화
    snakeHead.direction = RIGHT;
    snakeHead.SetPosition(ViewPortWwidth / 2, ViewPortHeight / 2);
    snakeHead.score = 0;

    //몸통 생성, 초기화
    for (int i = 0; i < InitLen; i++)
    {
        SnakeBody* snakebody = new SnakeBody();
        snakeHead.snakeTails.push_back(snakebody);
        gameScene.Hierarchy.push_back(snakebody);
        snakeHead.snakeTails[i]->SetPosition(snakeHead.Object_position_x - i, snakeHead.Object_position_y);
    }

    //음식 초기화
    food.SetPosition(rand() % (ViewPortWwidth-3), rand() % (ViewPortHeight-3));
    food.eaten = 0;

    //게임의 하이어라키에 머리,음식 저장
    gameScene.Hierarchy.push_back(&snakeHead);
    gameScene.Hierarchy.push_back(&food);

    /*Object* box = new Object;
    box->SetPosition(77, 25);
    gameScene.Hierarchy.push_back(box);*/

}


//unsigned long time_end = GetTickCount();
//unsigned long time1 = GetTickCount();

int PlayGame()
{
    RN = State_WormGame;

    gameScene.Draw();
    printf("\n\nScore : %d", snakeHead.score);

    /*time1 = GetTickCount() - time_end;
    time_end = GetTickCount();
    if (time1 < 33)
    {
        Sleep(33 - time1);
    }
    if (time1 != 0)
    {
        printf("\n\nScore : %d\ttime : %d \tfps : %d", snakeHead.score, time1, 1000 / time1);
    }*/


    handleInput();
    update();

	return RN;
}

void handleInput() {
    if (_kbhit()) {
        int key = _getch();
        switch (key) {
        case Key_UP:  // Up arrow
            if (snakeHead.direction != DOWN) {
                snakeHead.direction = UP;
            }
            break;
        case Key_DOWN:  // Down arrow
            if (snakeHead.direction != UP) {
                snakeHead.direction = DOWN;
            }
            break;
        case Key_LEFT:  // Left arrow
            if (snakeHead.direction != RIGHT) {
                snakeHead.direction = LEFT;
            }
            break;
        case Key_RIGHT:  // Right arrow
            if (snakeHead.direction != LEFT) {
                snakeHead.direction = RIGHT;
            }
            break;
        case Key_ESC:  // Esc key
            RN = State_Pause;
            break;
        case Key_ENTER:
            break;
        }
    }
}

void Dead()
{
    snakeHead.direction = RIGHT;
    snakeHead.SetPosition(ViewPortWwidth / 2, ViewPortHeight / 2);
    snakeHead.score = 0;

    int lastLength = snakeHead.snakeTails.size();

    for (int i = 0; i < lastLength; i++)
    {
        gameScene.Hierarchy.erase(std::find(gameScene.Hierarchy.begin(), gameScene.Hierarchy.end(), snakeHead.snakeTails[i]));
        //snakeHead.snakeTails.erase(std::find(snakeHead.snakeTails.begin(), snakeHead.snakeTails.end(), snakeHead.snakeTails[i]));
    }
    snakeHead.snakeTails.clear();

    for (int i = 0; i < InitLen; i++)
    {
        SnakeBody* snakebody = new SnakeBody();
        snakeHead.snakeTails.push_back(snakebody);
        gameScene.Hierarchy.push_back(snakebody);
        snakeHead.snakeTails[i]->SetPosition(snakeHead.Object_position_x - i, snakeHead.Object_position_y);
    }

    for (int i = 0; i < snakeHead.snakeTails.size(); i++)
    {
        snakeHead.snakeTails[i]->SetPosition(snakeHead.Object_position_x - i, snakeHead.Object_position_y);
    }

    food.SetPosition(rand() % (ViewPortWwidth-3), rand() % (ViewPortHeight-3));
    food.eaten = 0;


    //화면 버퍼 클리어
    for (int i = 0; i < (ViewPortWwidth+1) * ViewPortHeight; i++)
    {
        for (int j = 0; j < ViewPortHeight; j++)
        {
            for (int i = 0; i < ViewPortWwidth + 1; i++)
            {
                if (i == ViewPortWwidth)
                    gameScene.ScreenBuffer[i + (j * (ViewPortWwidth + 1))] = '\n';
                else
                {
                    if (i == 0 || i == (ViewPortWwidth - 1) || j == 0 || j == (ViewPortHeight - 1))
                        gameScene.ScreenBuffer[i + (j * (ViewPortWwidth + 1))] = '#';
                    else
                        gameScene.ScreenBuffer[i + (j * (ViewPortWwidth + 1))] = ' ';
                }
            }
        }
        gameScene.ScreenBuffer[ViewPortHeight * (ViewPortWwidth + 1) - 1] = '\0';
    }
}

void update()
{
    for (int i = snakeHead.snakeTails.size() - 1; i > 0; i--) 
    {
        snakeHead.snakeTails[i]->Erase();
        snakeHead.snakeTails[i]->SetPosition(snakeHead.snakeTails[i - 1]->Object_position_x, snakeHead.snakeTails[i - 1]->Object_position_y);
    }
    snakeHead.snakeTails[0]->SetPosition(snakeHead.Object_position_x, snakeHead.Object_position_y);

    switch (snakeHead.direction) {
    case UP:
        snakeHead.Object_position_y--;
        break;
    case DOWN:
        snakeHead.Object_position_y++;
        break;
    case LEFT:
        snakeHead.Object_position_x--;
        break;
    case RIGHT:
        snakeHead.Object_position_x++;
        break;
    }

    

    if (snakeHead.Object_position_x < 0 || snakeHead.Object_position_x >= ViewPortWwidth-2 || snakeHead.Object_position_y < 0 || snakeHead.Object_position_y >= ViewPortHeight-2)
    {
        RN = State_GameOver; // Hit the wall
        Dead();
        system("cls");
    }


    for (int i = 0; i < snakeHead.snakeTails.size(); i++) {
        if (snakeHead.Object_position_x == snakeHead.snakeTails[i]->Object_position_x && snakeHead.Object_position_y == snakeHead.snakeTails[i]->Object_position_y)
        {
            RN = State_GameOver; // Hit itself
            Dead();
            system("cls");
            break;
        }
    }

    if (snakeHead.Object_position_x == food.Object_position_x && snakeHead.Object_position_y == food.Object_position_y)
    {
        snakeHead.score++;
        SnakeBody* snakebody = new SnakeBody();
        snakeHead.snakeTails.push_back(snakebody);
        gameScene.Hierarchy.push_back(snakebody);

        food.eaten = 1;
    }

    if (food.eaten)
    {
        food.SetPosition(rand() % (ViewPortWwidth-3), rand() % (ViewPortHeight-3));
        food.eaten = 0;
    }
}
