// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include "selection-iterators/v8datamodel/Selection.h"

namespace RBX {

// INFERRED: the target is the compiler-generated thunk
// Selection::`vector deleting destructor'`adjustor{20}' (sub ecx,14h; jmp).
// Defining the destructor out of line in this unit makes the compiler emit
// the vftable and the thunk. This assumes the header declares the destructor
// without an inline body.
Selection::~Selection()
{
}

}
