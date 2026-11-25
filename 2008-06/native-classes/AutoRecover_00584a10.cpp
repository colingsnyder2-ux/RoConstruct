// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/ModelInstance.h"

namespace RBX {

// INFERRED: the target is the compiler-generated adjustor{20} thunk for
// ModelInstance's `vector deleting destructor' (sub ecx,14h; jmp real dtor).
// Defining the destructor out of line makes the compiler emit the vftable
// and this thunk. The header path above is a guess.
ModelInstance::~ModelInstance()
{
}

}
