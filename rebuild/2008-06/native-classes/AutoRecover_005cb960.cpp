// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include "v8tree/Instance.h"
#include "v8datamodel/UserController.h"

namespace RBX {

// INFERRED: explicit instantiation makes the compiler emit the
// `vector deleting destructor'`adjustor{16}' thunk (this -= 16; jmp ...)
// for the secondary-base vtable slot of FactoryProduct<ControllerService,...>.
// The previous failure came from including util/Object.h through two different
// include paths, so only the standard header paths are used now.
template class FactoryProduct<ControllerService, Instance, sControllerService>;

} // namespace RBX
