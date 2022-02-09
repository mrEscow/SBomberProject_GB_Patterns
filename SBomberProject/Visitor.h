#pragma once
#include "Bomb.h"
#include "Plane.h"
class IVisitor
{
public:
	virtual void log(const Bomb* bomb) = 0;
	virtual void log(const Plane* plane) = 0;
};

class LogVisitor :public IVisitor {
public:
	// Унаследовано через IVisitor
	virtual void log(const Bomb* bomb) override;
	virtual void log(const Plane* plane) override;
};