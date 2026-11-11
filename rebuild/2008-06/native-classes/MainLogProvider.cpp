// >>> native-status (generated) -- do not edit >>>
// MainLogProvider | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 5d84f93d | roc native-status --write
#include "CRobloxApp.h"

ThreadLogManager* currentThreadLogManager();

RBX::Log* MainLogManager::provideLog()
{
    if (GetCurrentThreadId() == threadId)
        return LogManager::getLog();
    return currentThreadLogManager()->getLog();
}
