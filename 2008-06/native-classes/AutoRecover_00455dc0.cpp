// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/Name.h"

namespace RBX {
    struct Stats {
        static char* sStats; // INFERRED: template argument from the mangled name
    };

    // INFERRED: Name::doDeclare is a private static member template declared in Name.h as
    // template<char** K> static const Name& doDeclare();
    // The disassembly passes a constant string and -1 to Name::declare, so it is specialized here.
    template<>
    const Name& Name::doDeclare<&Stats::sStats>()
    {
        // INFERRED: the string literal at 0x950c64 is not readable here; "Stats" is a guess.
        static const Name& name = Name::declare("Stats", -1);
        return name;
    }
}
