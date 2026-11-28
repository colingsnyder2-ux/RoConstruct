// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/Name.h"

namespace RBX {

// INFERRED: the symbol is an unbounded char array (it mangles as char*, 3PADA); the original pushes its address as an immediate.
extern char sControllerService[];

// INFERRED: the original is a template member of Name; the disassembly shows a function-local
// static reference initialised with declare(sControllerService, -1).
template<>
const Name& Name::doDeclare<&sControllerService>()
{
    static const Name& n = Name::declare(sControllerService, -1);
    return n;
}

}
