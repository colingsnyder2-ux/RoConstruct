// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: the listed convention (cdecl, 1 arg) does not match the disassembly.
// There is no push before the call and ecx still holds `this`, so this is a
// __thiscall member, declared here as __fastcall with the object pointer only.
extern "C" void __fastcall fn_00472920(void* self);

// INFERRED: this is a scalar deleting destructor. It runs the destructor body
// (fn_00472920), frees the object if bit 0 of the flags argument is set, and
// returns `this`.
extern "C" void* __fastcall fn_00473790(void* self, int unusedEdx, unsigned int flags)
{
    fn_00472920(self);
    if (flags & 1) {
        ::operator delete(self);
    }
    return self;
}
