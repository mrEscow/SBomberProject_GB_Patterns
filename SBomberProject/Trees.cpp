#include "Trees.h"
#include <new>
#include <iostream>
#include "MyTools.h"


using namespace std;
//using namespace MyTools;



DestroyableGroundObject* TreeCreatorA::Create(double x, double y)
{
	TreeA* Tree = new TreeA;
	y += MyTools::GetMaxY() - 6;
	Tree->SetPos(x, y);
    return  Tree;
}

DestroyableGroundObject* TreeCreatorB::Create(double x, double y)
{
	TreeB* Tree = new TreeB;
	Tree->SetWidth(15);
	const uint16_t maxY = MyTools::GetMaxY();
	y += MyTools::GetMaxY() - 6;
	Tree->SetPos(x,y);
	return  Tree;
}

DestroyableGroundObject* TreeCreatorC::Create(double x, double y)
{
	TreeC* Tree = new TreeC;
	Tree->SetWidth(15);
	const uint16_t maxY = MyTools::GetMaxY();
	y += MyTools::GetMaxY() - 6;
	Tree->SetPos(x, y);
	return  Tree;
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

bool __fastcall TreeA::isInside(double x1, double x2) const
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
bool __fastcall TreeB::isInside(double x1, double x2) const
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
bool __fastcall TreeC::isInside(double x1, double x2) const
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
