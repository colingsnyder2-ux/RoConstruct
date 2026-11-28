// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x00420910 (this-adjust thunk: this += 0x60, tail jump into mfc90 ordinal 820 = CString::operator=(const char*)); owning class unknown, so the CString member sits behind padding.
#include <afx.h>
struct Th_00420910
{
    char pad[0x60];
    CString s;
    CString& f(const char* v) { return s = v; }
};
CString& (Th_00420910::*keep_00420910)(const char*) = &Th_00420910::f;
