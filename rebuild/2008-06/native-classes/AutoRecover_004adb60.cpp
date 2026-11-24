// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: Creatable<Instance>::create-style helper returning a shared_ptr by hidden pointer (cdecl).
// 0x5e1a40: RBX::Lighting::Lighting()
extern "C" void* __fastcall fn_005e1a40(void* self, int unusedEdx);
// 0x4ad470: boost::shared_ptr<...>::shared_ptr(p, Creatable<Instance>::Deleter)
extern "C" void* __fastcall fn_004ad470(void* self, int unusedEdx, void* p, int deleter);

extern "C" void* fn_004adb60(void* ret)
{
    int deleter = 0; // INFERRED: one-byte Deleter flag, zero-initialised
    void* mem = malloc(0x2e0);
    void* obj = 0;
    if (mem)
        obj = fn_005e1a40(mem, 0);
    fn_004ad470(ret, 0, obj, deleter);
    return ret;
}
