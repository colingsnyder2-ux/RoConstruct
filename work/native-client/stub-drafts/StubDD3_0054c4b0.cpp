// native-flags: /Od /Ob0 /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: byte pattern (-Od scalar deleting destructor); class unknown, callee bare.
#include <new>
extern "C" void __fastcall fn_00551670(void* self);
extern "C" void* __fastcall fn_0054c4b0(void* self, int e, unsigned int f)
{
    fn_00551670(self);
    if (f & 1)
        ::operator delete(self);
    return self;
}
