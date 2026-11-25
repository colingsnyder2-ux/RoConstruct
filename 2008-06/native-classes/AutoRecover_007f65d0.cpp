// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

extern "C" void fn_005dc2f0();
extern "C" void fn_005d7550();
extern "C" void fn_007ff3a0();

// INFERRED: 12-byte by-value record {function, adjustor, 0} (member-pointer-like).
struct MemberFnRec {
    void* fn;
    int adj;
    int zero;
};

extern "C" int __fastcall fn_005da640(void* self, int unusedEdx,
                                      const char* a1, const char* a2,
                                      MemberFnRec a3, MemberFnRec a4, int a5);

// INFERRED: global object constructed at 0x0097a4b0 (static property descriptor)
extern char g_0097a4b0[];

extern "C" void fn_007f65d0()
{
    MemberFnRec getter;
    getter.fn = (void*)&fn_005dc2f0;
    getter.adj = -332;
    getter.zero = 0;

    MemberFnRec setter;
    setter.fn = (void*)&fn_005d7550;
    setter.adj = -332;
    setter.zero = 0;

    // INFERRED: edx is left holding -332 by the original (thiscall); reuse it as the dummy.
    fn_005da640(g_0097a4b0, -332, "TargetPoint", "Control", setter, getter, 4);
    atexit((void (__cdecl *)())fn_007ff3a0);
}
