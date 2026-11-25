// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <new>
#include "v8datamodel/Accoutrement.h"

// INFERRED: the target is the compiler-generated adjustor{304} thunk
// (sub ecx,0x130; jmp) for the vector deleting destructor of
// RBX::FactoryProduct<RBX::Hat, RBX::Accoutrement, &RBX::sHat>.
// The thunk has no source of its own, so, as in the twin, this helper
// constructs a Hat to force the vftable and thunk to be emitted.
// INFERRED: Hat.h does not exist; Accoutrement.h is assumed to declare
// Hat and the FactoryProduct base.
// The global placement new (::new) bypasses any private class-level
// operator new/delete.
RBX::Hat* createHatForVtable()
{
    void* mem = ::operator new(sizeof(RBX::Hat));
    return ::new (mem) RBX::Hat();
}
