
#include <conio.h>

#include "SBomber.h"
#include "ScreenSingletone.h"
#include "LoggerSingleton.h"

using namespace std;

//========================================================================================================================

int main(void)
{
    LoggerSingleton* FileLogger = &FileLoggerSingletone::getInstance();
    LoggerSingleton* ProxyLogger = &ProxyLoggerSingletone::getInstance();

    ProxyLogger->OpenLogFile("log.txt");

    SBomber game(ProxyLogger);

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        ScreenSingleton::getInstance().ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    FileLoggerSingletone::getInstance().CloseLogFile();

    return 0;
}
