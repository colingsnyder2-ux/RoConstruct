// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern at 0x00657c00 (this += 4, tail jump into msvcp90 std::locale::~locale; ArrowButton holds a locale at +4); owning class unknown.
#include <locale>
struct Th_00657c00
{
    char pad[4];
    std::locale loc;
    void f() { loc.~locale(); }
};
void (Th_00657c00::*keep_00657c00)() = &Th_00657c00::f;
