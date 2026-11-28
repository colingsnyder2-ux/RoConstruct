// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target is a compiler-generated adjustor{68} thunk (sub ecx,0x44; jmp vector deleting dtor)
// for a secondary-base vtable slot.
// INFERRED: as in the same-shape twin, the thunk is produced by defining the
// virtual destructor of Accoutrement out of line.
// INFERRED: assumes the real header declares a virtual ~Accoutrement() that can be defined here.
#include "v8datamodel/Accoutrement.h"

namespace RBX {

Accoutrement::~Accoutrement()
{
}

} // namespace RBX
