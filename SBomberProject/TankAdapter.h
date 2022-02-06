#pragma once
#include "DestroyableGroundObject.h"
#include "TankAdaptee.h"

class TankAdapter : public DestroyableGroundObject
{
private:
	TankAdaptee adaptee;
public:
	bool __fastcall isInside(double x1, double x2) const override {
	
	
	};

	inline uint16_t GetScore() const override { return adaptee.GetScore(); }

	void Draw() const override;
};

