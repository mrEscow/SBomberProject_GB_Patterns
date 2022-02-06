#include "TankAdapter.h"

bool __fastcall TankAdapter::isInside(double x1, double x2) const{
    return adaptee.isInRange(x1, x2);
}

//inline uint16_t TankAdapter::GetScore() const{
//    return adaptee.GetScore();
//}

void TankAdapter::Draw() const{
    const_cast<TankAdaptee*>(&adaptee)->Paint();
}

void TankAdapter::SetPos(double nx, double ny){
    adaptee.SetPos(nx, ny);
}

double TankAdapter::GetY() const{
    return adaptee.GetY();
}

double TankAdapter::GetX() const{
    return adaptee.GetX();
}

void TankAdapter::SetWidth(uint16_t widthN){
    adaptee.SetWidth(widthN);
}

uint16_t TankAdapter::GetWidth() const{
    return adaptee.GetWidth();
}









