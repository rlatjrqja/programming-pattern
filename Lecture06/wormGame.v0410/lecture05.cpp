#include <iostream>
#include <conio.h>

int key_input;
int gameStatus = 1; //1. 타이틀 2. 게임시작 3. 게임정보 4. 랭킹 5. 게임종료



void title()
{
    gameStatus = 1;
    std::cout << "***********************************\n";
    std::cout << "*                                 *\n";
    std::cout << "*                                 *\n";
    std::cout << "*          1. 게임시작            *\n";
    std::cout << "*          2. 게임설명            *\n";
    std::cout << "*          3. 게임랭킹            *\n";
    std::cout << "*          4. 게임종료 esc        *\n";
    std::cout << "*                                 *\n";
    std::cout << "*                                 *\n";
    std::cout << "***********************************\n";
}


void back()
{

    std::cout << "\n메뉴로 돌아가시겠습니까? Y/N\n";

    key_input = _getch();

    if (key_input == 'y')
    {
        title();
    }
    else if (key_input == 'n')
    {
        back();
    }
}

void inGame()
{
    gameStatus = 2;
    std::cout << "\n게임을 시작합니다.\n";
    back();
}

void gameInfo()
{
    gameStatus = 3;
    std::cout << "\n***********************************\n";
    std::cout << "          5주차 실습입니다\n";
    std::cout << "***********************************\n";
    back();
}

void ranking()
{
    gameStatus = 4;
    std::cout << "1위 김석범\n2위 이용석\n3위 최주하";
    back();
}

void page()
{
    if (gameStatus == 1)//타이틀 화면일때
    {
        switch (key_input)
        {
        case '1':
            inGame();
            break;
        case '2':
            gameInfo();
            break;
        case '3':
            ranking();
            break;
        case '4':
            exit;
            break;
        default:
            break;
        }
    }
    else if (gameStatus == 2)//인게임일때
    {
        inGame();
    }
    else if (gameStatus == 3)//게임정보
    {
        gameInfo();
    }
    else if (gameStatus == 4)//게임랭킹
    {
        ranking();
    }
}

int main()
{
    title();

    while (1)
    {
        if (_kbhit())
        {
            key_input = _getch();
            page();
        }
    }
}

