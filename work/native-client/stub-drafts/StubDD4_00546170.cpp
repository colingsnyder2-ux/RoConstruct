// native-flags: /Od /Ob0 /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS// INFERRED: byte pattern (-Od scalar deleting destructor, thiscall frame); class unknown, callee bare.
#include <new>
extern "C" void __fastcall fn_005461d0(void* self);
struct Z_00546170
{
    void* del(unsigned int f)
    {
        fn_005461d0(this);
        if (f & 1)
            ::operator delete(this);
        return this;
    }
};
void* (Z_00546170::*keep_00546170)(unsigned int) = &Z_00546170::del;
