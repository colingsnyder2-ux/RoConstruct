// >>> native-status (generated) -- do not edit >>>
// MainLogProvider | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 5d84f93d | roc native-status --write
#include "CRobloxApp.h"

ThreadLogManager* currentThreadLogManager();

RBX::Log* MainLogManager::provideLog()
{
    if (GetCurrentThreadId() == threadId)
        return LogManager::getLog();
    return currentThreadLogManager()->getLog();
}
