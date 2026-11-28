// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include "v8datamodel/Accoutrement.h"

// INFERRED: the target is the compiler-generated adjustor{16} thunk
// (this -= 16; jmp Accoutrement::`vector deleting destructor') for the
// secondary-base vtable slot. Defining the real destructor out of line makes
// the compiler emit the deleting-destructor and its adjustor thunk.
namespace RBX {

Accoutrement::~Accoutrement()
{
}

} // namespace RBX
