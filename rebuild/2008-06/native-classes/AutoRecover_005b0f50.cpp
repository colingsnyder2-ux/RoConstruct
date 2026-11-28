// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target is a compiler-generated adjustor thunk
// (sub ecx,0xc4 ; jmp real vector-deleting dtor) for the secondary base at
// offset 196 of RBX::Accoutrement. Defining the real class's virtual
// destructor out of line makes the compiler emit the vtable and the thunk.
// INFERRED: the header was not visible; I assumed it declares the destructor.
#include "v8datamodel/Accoutrement.h"

namespace RBX {

Accoutrement::~Accoutrement()
{
}

} // namespace RBX
