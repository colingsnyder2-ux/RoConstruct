// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

extern "C" int __fastcall fn_0045f340(void* self, int unusedEdx, int a1);
// shared_ptr<Script>::shared_ptr(Script*, Creatable<Instance>::Deleter)
extern "C" void* __fastcall fn_0045c0f0(void* self, int unusedEdx, void* p, int deleter);

// INFERRED: first arg is the sret shared_ptr<Script>, second is the Script ctor arg; Deleter is a 4-byte zeroed object.
extern "C" void* fn_0045f730(void* ret, int arg)
{
    int deleter = 0;
    void* mem = malloc(0x178);
    void* obj = 0;
    if (mem)
        obj = (void*)(size_t)fn_0045f340(mem, 0, arg), obj = mem;
    fn_0045c0f0(ret, 0, obj, deleter);
    return ret;
}
