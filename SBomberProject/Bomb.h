#pragma once

#include "DynamicObject.h"

class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // ��������� ����� � �����

	void Draw() const override;

	void __fastcall Accept(IVisitor* v)
	{
		v->log(*this);
	}

private:

};

