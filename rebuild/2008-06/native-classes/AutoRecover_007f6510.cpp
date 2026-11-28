// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: 12-byte by-value accessor, shaped like an MSVC member-function pointer
// for a class with virtual inheritance: {address, this-adjust, vbtable offset}.
struct MemberPtr12 {
    void* fn;
    int adj;
    int vb;
};

extern "C" int __fastcall fn_005da7e0(void* self, int unusedEdx, const char* name, const char* category, MemberPtr12 a, MemberPtr12 b, int flags);

extern "C" void fn_005dc090();
extern "C" void fn_005d7500();
extern "C" void fn_007ff3e0();

// INFERRED: global property descriptor object at 0x0097a2d8
extern "C" char g_0097a2d8[];

extern "C" void fn_007f6510()
{
    MemberPtr12 a;
    a.fn = (void*)&fn_005dc090;
    a.adj = -332;
    a.vb = 0;

    MemberPtr12 b;
    b.fn = (void*)&fn_005d7500;
    b.adj = -332;
    b.vb = 0;

    fn_005da7e0(g_0097a2d8, -332, "WalkRotationalVelocity", "Control", b, a, 4);
    atexit((void (__cdecl*)())fn_007ff3e0);
}
