
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

void BombDecorator::Move(uint16_t time)
{
    bomb.Move(time * 1.6);
}

void BombDecorator::Draw() const
{
    bomb.Draw();
    // Некоторое изменение внешнего вида бомбы
    ScreenSingleton::getInstance().GotoXY(bomb.GetX(), bomb.GetY() - 1);
    cout << "|";
}