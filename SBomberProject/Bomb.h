#pragma once

#include "DynamicObject.h"

class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;

private:

};

class BombDecorator : public DynamicObject
{
private:
	Bomb bomb;
public:
	void Draw() const override;
	void Move(uint16_t time) override;

	void SetPos(double nx, double ny) override { bomb.SetPos(nx, ny); }
	double GetY() const override { return bomb.GetY(); }
	double GetX() const override { return bomb.GetX(); }
	void SetWidth(uint16_t widthN) override { bomb.SetWidth(widthN); }
	uint16_t GetWidth() const override { bomb.GetWidth(); }

};