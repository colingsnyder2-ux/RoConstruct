// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x006e9360 (this += 8, tail jump into mfc90 ordinal 601 = CString::~CString); owning class unknown.
#include <afx.h>
struct Th_006e9360
{
    char pad[8];
    CString s;
    void f() { s.~CString(); }
};
void (Th_006e9360::*keep_006e9360)() = &Th_006e9360::f;
