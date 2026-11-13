// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-import-length /I{headers}/std-noinline-string
// Draft: original MFC string-helper imports and code generation are not yet matched.
#include "CRobloxApp.h"
#include "util/FileSystem.h"
#include <shlwapi.h>

static CString __stdcall logDirectory()
{
    std::string directory = RBX::FileSystem::getUserAppDataDirectory(true, "logs");
    return directory.c_str();
}

std::string MainLogManager::getLogPath()
{
    CString directory = logDirectory();
    std::string filename("log_");
    filename += logIdentity;
    filename.erase(12, std::string::npos);
    filename.erase(4, 3);
    filename += ".txt";
    const char* text = filename.c_str();
    char* buffer = directory.GetBuffer(CString::StringLength(text) + directory.GetLength() + 1);
    PathAppendA(buffer, text);
    directory.ReleaseBuffer();
    return std::string(static_cast<const char*>(directory));
}
