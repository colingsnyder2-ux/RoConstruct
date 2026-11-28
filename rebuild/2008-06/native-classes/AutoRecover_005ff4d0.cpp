// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include "v8datamodel/Mouse.h"

namespace RBX {

// INFERRED: the target is the compiler-generated thunk
// Mouse::`vector deleting destructor'`adjustor{20}' (sub ecx,14h; jmp to
// Mouse's own vector deleting destructor). The destructor is implicit in the
// real header, so it cannot be defined out of line. Instead, local
// construction and destruction force the compiler to emit Mouse's vftable,
// its vector deleting destructor, and the adjustor thunk for the secondary
// base at offset 20.
void Local_005ff4d0_force()
{
    Mouse m;
}

}
