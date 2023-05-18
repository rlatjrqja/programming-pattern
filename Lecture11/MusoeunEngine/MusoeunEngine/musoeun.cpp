#include <iostream>
#include <conio.h>
#include "MSEgameLoop.hpp"

int main()
{
    Musoeun::Scene scene;
    Musoeun::Object obj;
    scene.Hierarchy.push_back(obj);


    Musoeun::GameLoop gameLoop;
    gameLoop.Run();
}