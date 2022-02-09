#pragma once

#include <stdint.h>

#include "GameObject.h"

struct Direction
{
    double xDir;
    double yDir;
};

class DynamicObject : public GameObject 
{
public:

    DynamicObject() : speed(0.0), xDirction(0.0), yDirection(0) { }

    inline void SetSpeed(double sp) { speed = sp; }
    inline void SetDirection(double dx, double dy) { xDirction = dx; yDirection = dy; }
    
    virtual void Move(uint16_t time) { x += xDirction * speed * time * 0.001; y += yDirection * speed * time * 0.001; };

    virtual double GetSpeed() const { return speed; };
    virtual Direction GetDirection() const {
        Direction dir;
        dir.xDir = xDirction;
        dir.yDir = yDirection;
        return dir;
    };

protected:

    double speed;
    double xDirction, yDirection;

};