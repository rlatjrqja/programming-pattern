#include <iostream>
#include <conio.h>
#include <windows.h>

int key_input;
int gameStatus = 1; //0. 게임종료 1. 타이틀 2. 게임시작 3. 게임정보 4. 랭킹
int x, y;//화면의 가로세로 크기 입력용 변수
char** map;

void InitMap()
{
    if (map == NULL)
    {
        map = (char**)malloc(sizeof(char*));
    }
}


void drawScreen()
{
    for (int i = 1; i <= y + 1; i++) {
        for (int j = 1; j <= x + 1; j++) {
            if (i == 1 || i == y + 1 || j == 1 || j == x + 1) {
                std::cout << "  ";
            }
            else if (i == 2 || i == y || j == 2 || j == x) {
                std::cout << "* ";
            }
            else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}

void title()
{
    gameStatus = 1;
    drawScreen();
    

    COORD pos{ x / 2 - 3,y / 2 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    std::cout << "1. 게임시작";

    pos.X = x / 2 - 3; pos.Y = y / 2 + 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    std::cout << "2. 게임설명";

    pos.X = x / 2 - 3; pos.Y = y / 2 + 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    std::cout << "3. 게임랭킹";

    pos.X = x / 2 - 3; pos.Y = y / 2 + 3;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    std::cout << "4. 게임종료 esc";

    /*
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
    */
}


void back()
{

    std::cout << "\n메뉴로 돌아가시겠습니까? Y/N\n";

    key_input = _getch();

    if (key_input == 'y')
    {
        system("cls");
        title();
    }
    else if (key_input == 27)
    {
        gameStatus = 0;
    }
    else
    {
        back();
    }
    /*
    else if (key_input == 'n')
    {
        back();
    }
    */
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
        if(key_input>=48&& key_input<=57) system("cls");//아라비아 숫자일때만 화면을 클리어

        switch (key_input)
        {

        case '1':
            inGame();//인게임으로 이동
            break;
        case '2':
            gameInfo();//게임정보로 이동
            break;
        case '3':
            ranking();//랭킹 페이지로 이동
            break;
        case '4':
            exit;//
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
    std::cout << "12 이상의 가로 길이를 입력하세요: ";
    std::cin >> x;
    std::cout << "12 이상의 세로 길이를 입력하세요: ";
    std::cin >> y;

    
    title();

    while (1)
    {
        if (_kbhit())
        {
            key_input = _getch();

            if (key_input == 27) return 0;
            page();
        }
        if(gameStatus == 0) return 0;
    }
}
