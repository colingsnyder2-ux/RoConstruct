// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string
#include "CRobloxApp.h"

extern bool loggingEnabled;

RBX::Log* LogManager::getLog()
{
    if (!loggingEnabled)
        return 0;
    if (!log)
        log = new RBX::Log(getLogPath().c_str(), name.c_str());
    return log;
}
