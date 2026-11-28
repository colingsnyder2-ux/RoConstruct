// native-flags: /Od /Ob0 /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS// INFERRED: byte pattern (-Od scalar deleting destructor, thiscall frame); class unknown, callee bare.
#include <new>
extern "C" void __fastcall fn_00551670(void* self);
struct Z_0054c4b0
{
    void* del(unsigned int f)
    {
        fn_00551670(this);
        if (f & 1)
            ::operator delete(this);
        return this;
    }
};
void* (Z_0054c4b0::*keep_0054c4b0)(unsigned int) = &Z_0054c4b0::del;
