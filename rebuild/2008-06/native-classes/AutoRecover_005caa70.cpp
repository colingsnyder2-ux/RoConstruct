// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include "util/Object.h"
#include "v8tree/Instance.h"

namespace RBX {

// INFERRED: the target is the compiler-generated thunk
// FactoryProduct<ControllerService,Instance,&sControllerService>::
// `vector deleting destructor'`adjustor{20}'.
// It does `sub ecx,14h` and jumps to the primary vector deleting destructor.
// INFERRED: the include paths and the forward declaration below are guesses,
// because the real ControllerService header was not shown.
// INFERRED: the compiler reported that the template's name parameter is a
// plain `const char*`, so the argument is passed as a char array that decays
// to a pointer, not as the address of a char* variable.

class ControllerService;
extern char sControllerService[];

// Explicit instantiation emits the vftable and the adjustor{20} thunk.
template class FactoryProduct<ControllerService, Instance, sControllerService>;

}
