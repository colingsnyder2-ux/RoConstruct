// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: func_0045ecc0 is the Script ctor (thiscall, one stack arg); returns this.
extern "C" void* __fastcall fn_0045ecc0(void* self, int unusedEdx, int arg);

// INFERRED: boost::shared_ptr<Script>::shared_ptr(Script*, Creatable<Instance>::Deleter)
// at 0x45c250; thiscall, ecx = shared_ptr out, stack = (ptr, empty-deleter dword).
extern "C" void* __fastcall fn_0045c250(void* self, int unusedEdx, void* ptr, int deleter);

// INFERRED: cdecl; arg0 = shared_ptr<Script>* out (returned), arg1 = Script ctor arg.
// Equivalent to Creatable<Instance>::create<Script>(arg).
extern "C" void* fn_0045f020(void* out, int arg)
{
    void* mem = malloc(0x178);
    void* s = 0;
    if (mem)
        s = fn_0045ecc0(mem, 0, arg);
    fn_0045c250(out, 0, s, 0);
    return out;
}
