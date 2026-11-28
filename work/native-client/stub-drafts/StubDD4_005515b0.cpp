// native-flags: /Od /Ob0 /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS// INFERRED: byte pattern (-Od scalar deleting destructor, thiscall frame); class unknown, callee bare.
#include <new>
extern "C" void __fastcall fn_005515e0(void* self);
struct Z_005515b0
{
    void* del(unsigned int f)
    {
        fn_005515e0(this);
        if (f & 1)
            ::operator delete(this);
        return this;
    }
};
void* (Z_005515b0::*keep_005515b0)(unsigned int) = &Z_005515b0::del;
