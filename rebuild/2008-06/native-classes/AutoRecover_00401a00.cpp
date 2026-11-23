// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/Name.h"

namespace RBX {

// INFERRED: header declares template<char*& N> static const Name& doDeclare(); the
// disassembly passes the literal 'RunService' directly, so sRunService is a constant-initialized char*.
extern char* sRunService;

template<>
const Name& Name::doDeclare<&sRunService>()
{
    static const Name& n = Name::declare("RunService", -1);
    return n;
}

}
