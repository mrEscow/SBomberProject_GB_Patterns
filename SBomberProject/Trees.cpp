#include "Trees.h"
#include <new>
#include <iostream>
#include "MyTools.h"


using namespace std;
//using namespace MyTools;

bool __fastcall Tree::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

DestroyableGroundObject* TreeCreatorA::Create(double x, double y)
{
	Tree* tree = new TreeA;
	tree->SetWidth(15);
	const uint16_t maxY = MyTools::GetMaxY();
	y += MyTools::GetMaxY() - 6;
	tree->SetPos(x, y);
	return  tree;
}

DestroyableGroundObject* TreeCreatorB::Create(double x, double y)
{
	Tree* tree = new TreeB;
	tree->SetWidth(15);
	const uint16_t maxY = MyTools::GetMaxY();
	y += MyTools::GetMaxY() - 6;
	tree->SetPos(x, y);
	return  tree;
}

DestroyableGroundObject* TreeCreatorC::Create(double x, double y)
{
	Tree* tree = new TreeC;
	tree->SetWidth(15);
	const uint16_t maxY = MyTools::GetMaxY();
	y += MyTools::GetMaxY() - 6;
	tree->SetPos(x, y);
	return  tree;
}

void TreeA::Draw() const
{
	using namespace MyTools;

	MyTools::SetColor(CC_Magenta);
	GotoXY(x, y - 3);
	cout << "   #";
	GotoXY(x, y - 2);
	cout << "   #";
	GotoXY(x, y - 1);
	cout << "  ###";
	GotoXY(x, y);
	cout << "   #";
}

void TreeB::Draw() const
{
	using namespace MyTools;

	MyTools::SetColor(CC_Red);
	GotoXY(x, y - 7);
	cout << "   #";
	GotoXY(x, y - 6);
	cout << "   #";
	GotoXY(x, y - 5);
	cout << "  ###";
	GotoXY(x, y - 4);
	cout << "   #";
	GotoXY(x, y - 3);
	cout << " #####";
	GotoXY(x , y - 2);
	cout << "   #";
	GotoXY(x, y - 1);
	  cout << "#######";
	GotoXY(x, y);
	  cout << "   #";
}

void TreeC::Draw() const
{
	using namespace MyTools;

	MyTools::SetColor(CC_Green);

	cout << " #";
	GotoXY(x, y - 3);
	cout << " #   #";
	GotoXY(x, y - 2);
	cout << " ### #";
	GotoXY(x, y - 1);
	cout << "   ###";
	GotoXY(x, y);
	cout << "   #";
}


