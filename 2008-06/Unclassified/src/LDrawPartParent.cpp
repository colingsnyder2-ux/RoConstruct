// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// LDrawPartParent | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
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
