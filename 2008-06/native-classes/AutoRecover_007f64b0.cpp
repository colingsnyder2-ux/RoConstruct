// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: Three-word values represent member function pointers.
struct MemberFunction {
    void (__cdecl *function)();
    int adjustment;
    int virtualBase;
};

extern "C" char g_0097a4e8;
extern "C" void __cdecl fn_005d74d0();
extern "C" void __cdecl fn_005dbf80();
extern "C" void __cdecl fn_007ff400();

extern "C" int __fastcall fn_005da710(
    void* self, int unusedEdx, const char* name, const char* category,
    MemberFunction getter, MemberFunction setter, int flags);

extern "C" void __cdecl fn_007f64b0()
{
    MemberFunction getter = { fn_005d74d0, -332, 0 };
    MemberFunction setter = { fn_005dbf80, -332, 0 };
    fn_005da710(&g_0097a4e8, -332, "WalkDirection", "Control", setter, getter, 4);
    atexit(fn_007ff400);
}
