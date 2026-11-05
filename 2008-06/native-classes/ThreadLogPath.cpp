// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
#include "CRobloxApp.h"

extern MainLogManager* mainLogManager;

std::string ThreadLogManager::getLogPath()
{
    std::string result = mainLogManager->getLogPath();
    CString suffix;
    suffix.Format("_%s_%d", name.c_str(), threadId);
    result.insert(result.size() - 4, static_cast<const char*>(suffix));
    return result;
}
