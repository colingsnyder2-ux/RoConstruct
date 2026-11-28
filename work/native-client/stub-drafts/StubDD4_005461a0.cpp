// native-flags: /Od /Ob0 /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS// INFERRED: byte pattern (-Od scalar deleting destructor, thiscall frame); class unknown, callee bare.
#include <new>
extern "C" void __fastcall fn_005461f0(void* self);
struct Z_005461a0
{
    void* del(unsigned int f)
    {
        fn_005461f0(this);
        if (f & 1)
            ::operator delete(this);
        return this;
    }
};
void* (Z_005461a0::*keep_005461a0)(unsigned int) = &Z_005461a0::del;
