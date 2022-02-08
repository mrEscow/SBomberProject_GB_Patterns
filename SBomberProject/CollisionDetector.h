#pragma once
#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "Trees.h"
#include "House.h"
class ICollisionDetector
{
public:
	virtual void CheckPlaneAndLevelGUI(Plane* plane, LevelGUI* levelGUI, bool& exitFlag) = 0;
	virtual std::vector<Bomb*> CheckBombsAndGround(const std::vector<Bomb*>& AllBombs, Ground* pGround) = 0;
	virtual std::vector<DestroyableGroundObject*> __fastcall CheckDestoyableObjects(Bomb* pBomb, std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects, int16_t& score) = 0;
};

class CollisionDetector :public ICollisionDetector
{
public:
	// Унаследовано через ICollisionDetector
	virtual void CheckPlaneAndLevelGUI(Plane* plane, LevelGUI* levelGUI, bool& exitFlag) override;

	virtual std::vector<Bomb*> CheckBombsAndGround(const std::vector<Bomb*>& AllBombs, Ground* pGround) override;

	virtual std::vector<DestroyableGroundObject*> __fastcall CheckDestoyableObjects(Bomb* pBomb, std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects, int16_t& score) override;


};