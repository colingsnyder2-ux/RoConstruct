// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: Three-word values represent member-function pointers.
struct MemberPointer {
    void (*function)();
    int adjustment;
    int virtualOffset;
};

extern "C" void fn_005dc0c0();
extern "C" void fn_005d7510();
extern "C" void __cdecl fn_007ff420();
extern "C" char g_0097a4cc;

extern "C" void __fastcall fn_005da640(
    void* self, int unusedEdx, const char* name, const char* category,
    MemberPointer first, MemberPointer second, int flags);

extern "C" void __cdecl fn_007f6450()
{
    // INFERRED: Member-pointer roles and object type are unknown.
    MemberPointer second = { fn_005dc0c0, -332, 0 };
    MemberPointer first = { fn_005d7510, -332, 0 };

    fn_005da640(&g_0097a4cc, -332, "WalkToPoint", "Control", first, second, 4);
    atexit(fn_007ff420);
}
