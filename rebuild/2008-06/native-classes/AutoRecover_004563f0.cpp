// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: Name.h was found at util/Name.h (the earlier error was only about Stats.h).
// INFERRED: the Stats.h path below is a guess; no header excerpt was provided.
#include "util/Name.h"
#include "v8datamodel/Stats.h"

extern "C" void fn_00455dc0();

namespace RBX {

// INFERRED: assumes Name declares
//   template<char** P> static void callDoDeclare();
// and Stats declares
//   static char* sStats;
// Calling the void helper fn_00455dc0 as the last statement should compile to the single `jmp` in the target.
template<>
void Name::callDoDeclare<&Stats::sStats>()
{
    fn_00455dc0();
}

}
