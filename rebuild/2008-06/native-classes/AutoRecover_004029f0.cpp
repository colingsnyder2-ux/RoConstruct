// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/Name.h"

// INFERRED: the callee at 0x00401a00 is unnamed, so it is declared with the fn_ convention.
// The target is a tail jump to it, which is probably the inlined doDeclare body.
extern "C" void fn_00401a00();

namespace RBX {

// INFERRED: sRunService is declared as `extern char* sRunService`, matching the mangled template argument.
extern char* sRunService;

// INFERRED: Name::callDoDeclare is assumed to be declared in the header as a private static template member.
template<>
void Name::callDoDeclare<&sRunService>()
{
    fn_00401a00();
}

}
