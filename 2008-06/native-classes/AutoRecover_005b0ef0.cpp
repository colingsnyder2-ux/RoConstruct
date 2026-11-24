// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target is a compiler-generated vtordisp thunk for the vector deleting
// destructor of RBX::Accoutrement. The disassembly reads the vtordisp at [this-4],
// subtracts it, subtracts 0x1d0 to reach the most-derived object, and jumps to the
// real `vector deleting destructor' at 0x5b15c0. There is no source-level way to
// write that thunk, so the compiler emits it from the virtual destructor of a class
// with a virtual base. The header path below is a guess, since no header excerpt
// was provided.
#include "v8datamodel/Accoutrement.h"

namespace RBX {

// INFERRED: an out-of-line virtual destructor makes the compiler emit the scalar and
// vector deleting destructors plus the vtordisp adjustor thunk for the virtual-base layout.
Accoutrement::~Accoutrement()
{
}

}
