// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: stand-in for SignalDesc<RunService, void(float)> constructor (thiscall, 2 args)
struct DescDummy {
    void ctor(const char* name, const char* argName);
};

// INFERRED: global object at 0x973ca0
extern DescDummy g_00973ca0;

extern "C" void fn_007fcac0();

extern "C" void fn_007f2b70()
{
    g_00973ca0.ctor("DescendantRemoving", "descendant");
    atexit((int (__cdecl*)(void))0 == 0 ? (void(__cdecl*)(void))fn_007fcac0 : 0);
}
