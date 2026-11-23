// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <windows.h>
#include <shlobj.h>

// INFERRED: hidden return slot in [esp+0x120] is a std::string NRVO result; arg 2 is the CSIDL.
extern "C" std::string fn_0045af20(int csidl)
{
    std::string result;
    LPITEMIDLIST pidl;
    char path[MAX_PATH];
    if (SUCCEEDED(SHGetSpecialFolderLocation(0, csidl, &pidl)) &&
        SHGetPathFromIDListA(pidl, path))
        result = path;
    return result;
}
