// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <afxwin.h>

// INFERRED: the target is the compiler-generated scalar deleting destructor.
// It calls the CXTPDockingPaneSplitterContainer destructor (0x7616a0),
// then runs the global operator delete if bit 0 of the flags argument is set.
// The callee is declared with one fastcall argument so only ecx is loaded,
// which matches the __thiscall call in the disassembly.
struct Local_00761800;

extern "C" void __fastcall fn_007616a0(Local_00761800* self);

extern "C" Local_00761800* __fastcall fn_00761800(Local_00761800* self, int unusedEdx, unsigned int flags)
{
    fn_007616a0(self);
    if (flags & 1)
        operator delete((void*)self);
    return self;
}
