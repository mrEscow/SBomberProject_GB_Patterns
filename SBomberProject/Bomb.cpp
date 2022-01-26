
#include <iostream>

#include "Bomb.h"
#include "ScreenSingletone.h"

using namespace std;

void Bomb::Draw() const
{
    ScreenSingleton::getInstance().SetColor(CC_LightMagenta);
    ScreenSingleton::getInstance().GotoXY(x, y);
    cout << "*";
}