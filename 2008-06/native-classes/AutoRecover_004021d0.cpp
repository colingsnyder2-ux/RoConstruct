// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>

// INFERRED: no CRegParser header was available, so the ATL member
// CRegParser::HasSubKeys(HKEY) is defined as an extern "C" fastcall function
// with the object pointer first and a dummy edx argument.
extern "C" BOOL __fastcall fn_004021d0(void* self, int unusedEdx, HKEY hkey)
{
    DWORD dwSubKeys = 0;
    LONG lRes = RegQueryInfoKeyA(hkey, NULL, NULL, NULL, &dwSubKeys,
                                 NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    if (lRes != ERROR_SUCCESS)
        return FALSE;
    return dwSubKeys > 0;
}
