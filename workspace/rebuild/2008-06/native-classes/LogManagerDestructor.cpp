// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// LogManagerDestructor | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by colin (chatgpt:gpt-6.1-sol)
// <<< native-status | src 894d1b41 | roc native-status --write
#include "CRobloxApp.h"

std::string archiveFile(const char* path, std::string directory);

LogManager::~LogManager()
{
    if (log) {
        std::string path(log->logFile);
        RBX::Log::Severity severity = log->worstSeverity;
        delete log;
        log = 0;
        if (severity == RBX::Log::Error)
            archiveFile(path.c_str(), "error\\");
        else
            archiveFile(path.c_str(), "archive\\");
    }
}
