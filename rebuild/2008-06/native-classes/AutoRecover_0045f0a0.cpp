// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: func_0045eef0 is the RBX::Script ctor (object size 0x178), one stack arg.
extern "C" void* __fastcall fn_0045eef0(void* self, int unusedEdx, void* arg);
// INFERRED: func_0045c300 is boost::shared_ptr<Script>::shared_ptr<Script, Creatable<Instance>::Deleter>(p, d); the Deleter is an empty 4-byte value.
extern "C" void* __fastcall fn_0045c300(void* self, int unusedEdx, void* p, int deleter);

extern "C" void* fn_0045f0a0(void* out, void* arg)
{
    int deleter = 0;
    void* p = malloc(0x178);
    void* obj = 0;
    if (p)
        obj = fn_0045eef0(p, 0, arg);
    fn_0045c300(out, 0, obj, deleter);
    return out;
}
