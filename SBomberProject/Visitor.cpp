#include "Visitor.h"

#include "Bomb.h"
#include "Plane.h"

#include "MyTools.h"
using namespace MyTools;

void LogVisitor::log(const Bomb* bomb)
{
	MyTools::WriteToLog(
		"BombSpeed: ",
		bomb->GetSpeed()
	);
	MyTools::WriteToLog(
		"BombDirection: ",
		bomb->GetDirection().xDir,
		bomb->GetDirection().yDir
	);
}

void LogVisitor::log(const Plane* plane)
{
	MyTools::WriteToLog(
		"BombSpeed: ",
		plane->GetSpeed()
	);

	MyTools::WriteToLog(
		"BombDirection: ",
		plane->GetDirection().xDir,
		plane->GetDirection().yDir
	);
}
