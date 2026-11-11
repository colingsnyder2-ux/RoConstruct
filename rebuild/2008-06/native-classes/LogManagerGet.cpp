// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// LogManagerGet | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 552523d3 | roc native-status --write
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
