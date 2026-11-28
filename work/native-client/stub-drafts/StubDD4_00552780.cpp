// native-flags: /Od /Ob0 /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS// INFERRED: byte pattern (-Od scalar deleting destructor, thiscall frame); class unknown, callee bare.
#include <new>
extern "C" void __fastcall fn_00552160(void* self);
struct Z_00552780
{
    void* del(unsigned int f)
    {
        fn_00552160(this);
        if (f & 1)
            ::operator delete(this);
        return this;
    }
};
void* (Z_00552780::*keep_00552780)(unsigned int) = &Z_00552780::del;
