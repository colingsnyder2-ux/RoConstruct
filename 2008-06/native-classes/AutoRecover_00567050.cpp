// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include "selection-iterators/v8datamodel/Selection.h"

// INFERRED: the target is the compiler-generated adjustor thunk
// (this -= 16; jmp Selection::`vector deleting destructor') for the
// secondary-base vtable slot of RBX::Selection. The real class comes from the
// header, so defining its destructor makes the compiler emit the vtable, the
// vector deleting destructor and this thunk.
namespace RBX {

Selection::~Selection()
{
}

} // namespace RBX
