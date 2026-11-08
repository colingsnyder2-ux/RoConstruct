// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// LDrawPartWrite | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src 5afe52e2 | roc native-status --write
#include "util/LDrawEntities.h"

namespace RBX { namespace LDraw2Lua {
bool LDrawPart::writeLua(std::ostream& out, std::string parent) const
{
    if (type == 1) {
        LDraw2RobloxPartMap* entry = output->findPartCaseInsensitive(name);
        if (entry) {
            NativeRobloxPart* part = entry->getPart();
            if (part) {
                writeShape(out, part);
                writeColor(out);
                writeTransform(out, part->offset);
                writeParent(out, parent);
                out << "\n";
                return true;
            }
        }
    }
    return false;
}
} }
