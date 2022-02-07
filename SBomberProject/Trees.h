#pragma once

#include "DestroyableGroundObject.h"

/**
 * Интерфейс Продукта объявляет операции, которые должны выполнять все
 * конкретные продукты.
 */

//DestroyableGroundObject 
class Tree : public DestroyableGroundObject
{
public:
	virtual bool __fastcall isInside(double x1, double x2) const override;
	virtual ~Tree() {};
};

/**
 * Конкретные Продукты предоставляют различные реализации интерфейса Продукта.
 */
class TreeA : public Tree {
public:
	// Унаследовано через DestroyableGroundObject
	virtual void Draw() const override;
	virtual uint16_t GetScore() const override { return 100; };

};
class TreeB : public Tree {
public:
	// Унаследовано через DestroyableGroundObject
	virtual void Draw() const override;
	virtual uint16_t GetScore() const override { return 350; };
};
class TreeC : public Tree {
public:
	// Унаследовано через DestroyableGroundObject
	virtual void Draw() const override;
	virtual uint16_t GetScore() const override { return 550; };

};

/**
 * Класс Создатель объявляет фабричный метод, который должен возвращать объект
 * класса Продукт. Подклассы Создателя обычно предоставляют реализацию этого
 * метода.
 */
class TreeCreator {
public:
	virtual ~TreeCreator() {};
	virtual DestroyableGroundObject* Create(double x, double y)=0;
}; 
/**
 * Конкретные Создатели переопределяют фабричный метод для того, чтобы изменить
 * тип результирующего продукта.
 */
class TreeCreatorA : public TreeCreator {
	// Унаследовано через TreeCreator
	virtual DestroyableGroundObject* Create(double x, double y) override;
};
class TreeCreatorB : public TreeCreator {
	// Унаследовано через TreeCreator
	virtual DestroyableGroundObject* Create(double x, double y) override;
};
class TreeCreatorC : public TreeCreator {
	// Унаследовано через TreeCreator
	virtual DestroyableGroundObject* Create(double x, double y) override;
};
