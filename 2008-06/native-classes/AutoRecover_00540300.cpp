// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: the disassembly pushes no stack args for this call, so it is declared with none.
extern "C" int __fastcall fn_0053f160(void* self, int unusedEdx);

// INFERRED: this is a scalar deleting destructor: run the destructor body, then delete if (flags & 1).
extern "C" void* __fastcall fn_00540300(void* self, int unusedEdx, unsigned int flags)
{
    fn_0053f160(self, 0);
    if (flags & 1) {
        ::operator delete(self);
    }
    return self;
}
