// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x006d0e90 (this-adjust thunk: this += 0x280, tail jump into mfc90 ordinal 820 = CString::operator=(const char*)); owning class unknown, so the CString member sits behind padding.
#include <afx.h>
struct Th_006d0e90
{
    char pad[0x280];
    CString s;
    CString& f(const char* v) { return s = v; }
};
CString& (Th_006d0e90::*keep_006d0e90)(const char*) = &Th_006d0e90::f;
