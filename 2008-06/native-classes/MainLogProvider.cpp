#include "CRobloxApp.h"

ThreadLogManager* currentThreadLogManager();

RBX::Log* MainLogManager::provideLog()
{
    if (GetCurrentThreadId() == threadId)
        return LogManager::getLog();
    return currentThreadLogManager()->getLog();
}
