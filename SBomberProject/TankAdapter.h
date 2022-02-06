#pragma once
#include "DestroyableGroundObject.h"
#include "TankAdaptee.h"

class TankAdapter : public DestroyableGroundObject
{
private:
	TankAdaptee adaptee;
public:
	bool __fastcall isInside(double x1, double x2) const override;
	inline uint16_t GetScore() const override;
	void Draw() const override;

	void SetPos(double nx, double ny) override;
	double GetY() const override;
	double GetX() const override;
	void SetWidth(uint16_t widthN) override;
	uint16_t GetWidth() const override;
};

