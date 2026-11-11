// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// LDrawPartParent | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src 8e3caf04 | roc native-status --write
#include "util/LDrawEntities.h"

namespace RBX { namespace LDraw2Lua {
bool LDrawPart::writeParent(std::ostream& out, std::string parent) const
{
    out << "part.Parent = " << parent.c_str();
    out << "\n";
    out << "part:MakeJoints()";
    out << "\n";
    return false;
}
} }
