#pragma once
#include "DynamicObject.h"
#include <vector>
#include "Plane.h"
#include "FileLoggerSingletone.h"
#include <string>
#include "Bomb.h"
#include "Ground.h"


/**
 * Паттерн Команда
 *
 * Назначение: Превращает запросы в объекты, позволяя передавать их как
 * аргументы при вызове методов, ставить запросы в очередь, логировать их, а
 * также поддерживать отмену операций.
 */
 /**
  * Интерфейс Команды объявляет метод для выполнения команд.
  */
class AbstractCommand
{
public:
	virtual ~AbstractCommand() {
		//delete pSBomber;
	}
	virtual bool Execute() const = 0;

	//void setDocument(SBomber* _doc)
	//{
	//	pSBomber = _doc;
	//}
};
/**
 * Некоторые команды способны выполнять простые операции самостоятельно.
 */
class DeleteDynamicObj : public AbstractCommand
{
private:
	DynamicObject* pObj_;
	std::vector<DynamicObject*>& vecDynamicObj_;
public:
	DeleteDynamicObj(DynamicObject* pObj, std::vector<DynamicObject*>& vecDynamicObj)
		:	pObj_(pObj),
			vecDynamicObj_(vecDynamicObj){}

	~DeleteDynamicObj() { delete pObj_; }

	virtual bool Execute() const override {
		auto it = vecDynamicObj_.begin();
		for (; it != vecDynamicObj_.end(); it++)
		{
			if (*it == pObj_)
			{
				vecDynamicObj_.erase(it);
				break;
			}
		}
		return true;
	}
};
/**
 * Некоторые команды способны выполнять простые операции самостоятельно.
 */
class DeleteStaticObj : public AbstractCommand
{
private:
	GameObject* pObj_;
	std::vector<GameObject*>& vecStaticObj_;
public:
	DeleteStaticObj(GameObject* pObj, std::vector<GameObject*>& vecStaticObj)
		: pObj_(pObj),
		vecStaticObj_(vecStaticObj) {}

	~DeleteStaticObj() { delete pObj_; }

	virtual bool Execute() const override {
		auto it = vecStaticObj_.begin();
		for (; it != vecStaticObj_.end(); it++)
		{
			if (*it == pObj_)
			{
				vecStaticObj_.erase(it);
				break;
			}
		}
		return true;
	}
};

class DropBomb : public AbstractCommand
{
private:
	//SBomber* receiver_;
	const Plane* pPlane_;
	std::vector<DynamicObject*>& vecDynamicObj_;
	mutable  uint16_t* pbombsNumber_;
	double speed_;
	CraterSize eCraterSize_;
public:
	DropBomb(
		const Plane* plane, 
		std::vector<DynamicObject*>& vecDynamicObj,
		uint16_t* bombsNumber,
		double speed = 2,
		CraterSize CraterSize = SMALL_CRATER_SIZE
	)
		: 
		vecDynamicObj_(vecDynamicObj),
		pPlane_(plane),
		pbombsNumber_(bombsNumber),
		speed_(speed),
		eCraterSize_(CraterSize)
	{}

	virtual bool Execute() const override {
		if (*pbombsNumber_ > 0)
		{
			FileLoggerSingletone::getInstance().WriteToLog(std::string(__FUNCTION__) + " was invoked");

			double x = pPlane_->GetX() + 4;
			double y = pPlane_->GetY() + 2;

			Bomb* pBomb = new Bomb;
			pBomb->SetDirection(0.3, 1);
			pBomb->SetSpeed(speed_);
			pBomb->SetPos(x, y);
			pBomb->SetWidth(SMALL_CRATER_SIZE);

			vecDynamicObj_.push_back(pBomb);

			
			if (pbombsNumber_)
				(*pbombsNumber_)--;

			return true;
		}
		return false;
	}
};
