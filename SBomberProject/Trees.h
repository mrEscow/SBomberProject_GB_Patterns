#pragma once

#include "DestroyableGroundObject.h"

/**
 * ��������� �������� ��������� ��������, ������� ������ ��������� ���
 * ���������� ��������.
 */

//DestroyableGroundObject 
class Tree : public DestroyableGroundObject
{
public:
	virtual bool __fastcall isInside(double x1, double x2) const override;
	virtual ~Tree() {};
};

/**
 * ���������� �������� ������������� ��������� ���������� ���������� ��������.
 */
class TreeA : public Tree {
public:
	// ������������ ����� DestroyableGroundObject
	virtual void Draw() const override;
	virtual uint16_t GetScore() const override { return 100; };

};
class TreeB : public Tree {
public:
	// ������������ ����� DestroyableGroundObject
	virtual void Draw() const override;
	virtual uint16_t GetScore() const override { return 350; };
};
class TreeC : public Tree {
public:
	// ������������ ����� DestroyableGroundObject
	virtual void Draw() const override;
	virtual uint16_t GetScore() const override { return 550; };

};

/**
 * ����� ��������� ��������� ��������� �����, ������� ������ ���������� ������
 * ������ �������. ��������� ��������� ������ ������������� ���������� �����
 * ������.
 */
class TreeCreator {
public:
	virtual ~TreeCreator() {};
	virtual DestroyableGroundObject* Create(double x, double y)=0;
}; 
/**
 * ���������� ��������� �������������� ��������� ����� ��� ����, ����� ��������
 * ��� ��������������� ��������.
 */
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
