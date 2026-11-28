// native-flags: /Od /Ob0 /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS// INFERRED: byte pattern (-Od scalar deleting destructor, thiscall frame); class unknown, callee bare.
#include <new>
extern "C" void __fastcall fn_00547020(void* self);
struct Z_00546ff0
{
    void* del(unsigned int f)
    {
        fn_00547020(this);
        if (f & 1)
            ::operator delete(this);
        return this;
    }
};
void* (Z_00546ff0::*keep_00546ff0)(unsigned int) = &Z_00546ff0::del;
