// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include "v8datamodel/Accoutrement.h"

namespace RBX {

// INFERRED: the target is the compiler-generated thunk
// `Accoutrement::`vector deleting destructor'`adjustor{20}'`.
// It does `sub ecx,14h` and jumps to Accoutrement's own vector deleting
// destructor. Defining the destructor out of line against the real header
// makes the compiler emit the vector deleting destructor and its adjustor
// thunk.
Accoutrement::~Accoutrement()
{
}

}
