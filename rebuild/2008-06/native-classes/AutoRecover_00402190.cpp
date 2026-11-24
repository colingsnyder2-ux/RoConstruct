// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>

// INFERRED: table of 12 key-name strings at 0x80add8 (ATL CRegParser never-delete list)
extern "C" const char* const g_0080add8[12];

// INFERRED: ATL CRegParser::CanForceRemoveKey shape; returns 0 on match, 1 otherwise
extern "C" int __stdcall fn_00402190(const char* lpszKey)
{
    for (int i = 0; i < 12; i++)
    {
        if (!lstrcmpiA(lpszKey, g_0080add8[i]))
            return 0;
    }
    return 1;
}
