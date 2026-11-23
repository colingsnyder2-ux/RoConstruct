// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: Script ctor (0x5c9f70) is thiscall with one stack arg; shared_ptr<Script,Deleter> ctor (0x5c92e0) is thiscall (ptr, deleter).
extern "C" void __fastcall fn_005c9f70(void* self, int unusedEdx, void* arg);
extern "C" void __fastcall fn_005c92e0(void* self, int unusedEdx, void* ptr, int deleter);

// INFERRED: sret-style factory returning boost::shared_ptr<RBX::Script> via hidden first arg
extern "C" void* fn_005ca1c0(void* ret, void* arg)
{
    int deleter = 0;
    void* p = malloc(0x160);
    if (p)
        fn_005c9f70(p, 0, arg);
    fn_005c92e0(ret, 0, p, deleter);
    return ret;
}
