#include <iostream>
#include "TankAdaptee.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void TankAdaptee::Paint()
{
	MyTools::SetColor(CC_Brown);
	GotoXY(x, y - 3);
	cout << "    #####";
	GotoXY(x - 2, y - 2);
	cout << "#######   #";
	GotoXY(x, y - 1);
	cout << "    #####";
	GotoXY(x, y);
	cout << " ###########";
}

bool __fastcall TankAdaptee::isInRange(double x1, double x2) const
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
