// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <new>
#include "v8datamodel/Accoutrement.h"

// INFERRED: the target is the compiler-generated adjustor{304} thunk
// (sub ecx,0x130; jmp) for the vector deleting destructor of
// RBX::Accoutrement. The thunk has no source of its own, so, as in the
// twin, this helper constructs an Accoutrement to force the vftable and
// thunk to be emitted.
// The global placement new (::new) bypasses any private class-level
// operator new/delete.
RBX::Accoutrement* createAccoutrementForVtable()
{
    void* mem = ::operator new(sizeof(RBX::Accoutrement));
    return ::new (mem) RBX::Accoutrement();
}
