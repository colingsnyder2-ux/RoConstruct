// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: this function is a compiler-generated adjustor thunk (this -= 16, then jump to
// the real vector deleting destructor). It cannot be written by hand, so the source forces
// the compiler to emit it by explicitly instantiating the template.
// INFERRED: the ControllerService header path is unknown (v8datamodel/ControllerService.h does
// not exist), so only Instance.h is included and ControllerService is declared locally.
#include "v8tree/Instance.h"

namespace RBX {
    // INFERRED: the template's non-type parameter is a const char* (per the compiler error),
    // and the mangling "3PADA" for the variable is how MSVC 2008 mangles a char array,
    // so the name is a non-const char array whose address is the template argument.
    extern char sControllerService[];

    // INFERRED: minimal local stand-in for the real ControllerService class.
    class ControllerService : public Instance {
    };

    // INFERRED: explicit instantiation emits the virtual destructor, including its
    // `vector deleting destructor' and the `adjustor{16}' thunk for the secondary base.
    template class FactoryProduct<ControllerService, Instance, sControllerService>;
}
