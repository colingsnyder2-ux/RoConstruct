// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: this is boost::shared_ptr<Script>::create-style code (Creatable<Instance>::create<Script>(arg)).
// It returns its hidden result pointer in eax.
extern "C" int __fastcall fn_0045f340(void* self, int unusedEdx, int a1);
// INFERRED: shared_ptr<Script>(Script*, Creatable<Instance>::Deleter) ctor; the Deleter is passed as one dword.
extern "C" void* __fastcall fn_0045c0f0(void* self, int unusedEdx, void* p, int deleter);

extern "C" void* fn_0045f730(void* result, int arg)
{
    // INFERRED: Deleter holds a bool flag, initially false
    int deleter = 0;
    void* mem = malloc(0x178);
    void* obj = 0;
    if (mem)
    {
        fn_0045f340(mem, 0, arg);
        obj = mem;
    }
    fn_0045c0f0(result, 0, obj, deleter);
    return result;
}
