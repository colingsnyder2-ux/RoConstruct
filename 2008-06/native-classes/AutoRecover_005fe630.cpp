// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include "v8datamodel/Tool.h"

// INFERRED: the target is the compiler-generated adjustor thunk
// (this -= 16; jmp RBX::Tool::`vector deleting destructor') for the secondary-base
// vtable slot of RBX::Tool. It is emitted when the real class's virtual destructor
// is defined, so the destructor is defined here using the real header.

namespace RBX {

// INFERRED: assumes Tool.h declares a virtual ~Tool() that is not defined inline.
Tool::~Tool()
{
}

} // namespace RBX
