// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: The target is the compiler-generated adjustor{36} thunk for
// Accoutrement's vector deleting destructor ("sub ecx,0x24; jmp
// Accoutrement::`vector deleting destructor'"). It is emitted in the
// translation unit that emits Accoutrement's vftable. Defining the destructor
// out of line from the real header makes the compiler emit the vftables, the
// vector deleting destructor and the adjustor thunk.
#include "v8datamodel/Accoutrement.h"

namespace RBX {

// INFERRED: assumes the header declares `virtual ~Accoutrement();` without an inline body.
Accoutrement::~Accoutrement() {}

} // namespace RBX
