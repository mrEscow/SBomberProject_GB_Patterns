#include "CollisionDetector.h"
#include "LevelGUI.h"
#include "Plane.h"
#include <vector>
#include "Ground.h"
#include "DestroyableGroundObject.h"

void CollisionDetector::CheckPlaneAndLevelGUI(Plane* plane, LevelGUI* levelGUI, bool& exitFlag)
{
    if (plane->GetX() > levelGUI->GetFinishX())
    {
        exitFlag = true;
    }
}


std::vector<Bomb*> CollisionDetector::CheckBombsAndGround(const std::vector<Bomb*>& AllBombs, Ground* pGround)
{
    std::vector<Bomb*> vecDestroyBobms;
    std::vector<Bomb*> vecBombs = AllBombs;
    
    const double y = pGround->GetY();
    for (size_t i = 0; i < vecBombs.size(); i++)
    {
        if (vecBombs[i]->GetY() >= y) // Пересечение бомбы с землей
        {
            pGround->AddCrater(vecBombs[i]->GetX());
            //CheckDestoyableObjects(vecBombs[i]);
            //DeleteDynamicObj(vecBombs[i]);
            vecDestroyBobms.push_back(vecBombs[i]);
        }
    }

    return vecDestroyBobms;
}

std::vector<DestroyableGroundObject*> __fastcall CollisionDetector::CheckDestoyableObjects(Bomb* pBomb, std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects, int16_t& score)
{
    std::vector<DestroyableGroundObject*> vecDestroyObjs;
    std::vector<DestroyableGroundObject*> vecDestoyableObjects = FindDestoyableGroundObjects;
    const double size = pBomb->GetWidth();
    const double size_2 = size / 2;
    for (size_t i = 0; i < vecDestoyableObjects.size(); i++)
    {
        const double x1 = pBomb->GetX() - size_2;
        const double x2 = x1 + size;
        if (vecDestoyableObjects[i]->isInside(x1, x2))
        {
            score += vecDestoyableObjects[i]->GetScore();
            vecDestroyObjs.push_back(vecDestoyableObjects[i]);
        }
    }
    return vecDestroyObjs;
}


