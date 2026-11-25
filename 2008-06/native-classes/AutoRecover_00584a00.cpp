// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include "v8datamodel/ModelInstance.h"

// INFERRED: no class header excerpt was provided, so the include path above is a guess.
// The target is the compiler-generated adjustor{16} thunk (this -= 16; jmp to the
// vector deleting destructor) for the secondary-base vtable slot of
// RBX::ModelInstance. The compiler emits it when ModelInstance's virtual destructor
// is defined, so the destructor definition below is what produces the thunk.
namespace RBX {

ModelInstance::~ModelInstance()
{
}

} // namespace RBX
