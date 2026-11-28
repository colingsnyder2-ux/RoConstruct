// native-flags: /Od /Ob0 /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS// INFERRED: byte pattern (-Od scalar deleting destructor, thiscall frame); class unknown, callee bare.
#include <new>
extern "C" void __fastcall fn_00541030(void* self);
struct Z_00541260
{
    void* del(unsigned int f)
    {
        fn_00541030(this);
        if (f & 1)
            ::operator delete(this);
        return this;
    }
};
void* (Z_00541260::*keep_00541260)(unsigned int) = &Z_00541260::del;
