// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: no push before the call and no stack cleanup after it, so ecx (this) goes straight through: __thiscall, not the cdecl the hint suggested.
extern "C" void __fastcall fn_004e85f0(void* self, int unusedEdx);

// INFERRED: scalar deleting destructor shape (dtor body, then delete if flags & 1).
extern "C" void* __fastcall fn_004e9000(void* self, int unusedEdx, unsigned int flags)
{
    fn_004e85f0(self, 0);
    if (flags & 1)
        ::operator delete(self);
    return self;
}
