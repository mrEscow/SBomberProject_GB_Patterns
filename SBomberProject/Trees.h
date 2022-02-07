#pragma once

#include "DestroyableGroundObject.h"

/**
 * ��������� �������� ��������� ��������, ������� ������ ��������� ���
 * ���������� ��������.
 */

//DestroyableGroundObject 

/**
 * ���������� �������� ������������� ��������� ���������� ���������� ��������.
 */
class TreeA : public DestroyableGroundObject {
public:
	// ������������ ����� DestroyableGroundObject
	virtual void Draw() const override;

	virtual bool __fastcall isInside(double x1, double x2) const override;

	virtual uint16_t GetScore() const override { return 100; };

};
class TreeB : public DestroyableGroundObject {
public:
	// ������������ ����� DestroyableGroundObject
	virtual void Draw() const override;

	virtual bool __fastcall isInside(double x1, double x2) const override;

	virtual uint16_t GetScore() const override { return 350; };

};

class TreeC : public DestroyableGroundObject {
public:
	// ������������ ����� DestroyableGroundObject
	virtual void Draw() const override;

	virtual bool __fastcall isInside(double x1, double x2) const override;

	virtual uint16_t GetScore() const override { return 550; };

};

class TreeCreator {
public:
	virtual DestroyableGroundObject* Create(double x, double y)=0;
}; 
class TreeCreatorA : public TreeCreator {
	// ������������ ����� TreeCreator
	virtual DestroyableGroundObject* Create(double x, double y) override;
};
class TreeCreatorB : public TreeCreator {
	// ������������ ����� TreeCreator
	virtual DestroyableGroundObject* Create(double x, double y) override;
};
class TreeCreatorC : public TreeCreator {
	// ������������ ����� TreeCreator
	virtual DestroyableGroundObject* Create(double x, double y) override;
};
