// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: 12-byte by-value descriptor (function pointer, this-adjust, zero), passed on the stack
struct Local_007f6570 {
    void* fn;
    int adj;
    int zero;
};

extern "C" void fn_005dc270();
extern "C" void fn_005d7520();
extern "C" void fn_007ff3c0();
extern "C" char g_0097a26c[];

// INFERRED: the 9 stack arguments are two strings, two 12-byte structs and the int 4
extern "C" int __fastcall fn_005da8b0(void* self, int unusedEdx,
                                      const char* name, const char* group,
                                      Local_007f6570 b, Local_007f6570 a, int flags);

extern "C" void fn_007f6570()
{
    // INFERRED: edx still holds the adjust value (-332) at the call, so it is passed as the dummy edx
    const int adj = -332;

    Local_007f6570 a;
    a.fn = (void*)fn_005dc270;
    a.adj = adj;
    a.zero = 0;

    Local_007f6570 b;
    b.fn = (void*)fn_005d7520;
    b.adj = adj;
    b.zero = 0;

    fn_005da8b0(g_0097a26c, adj, "Jump", "Control", b, a, 4);
    atexit(fn_007ff3c0);
}
