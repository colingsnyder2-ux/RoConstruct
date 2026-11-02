#include "NativeLDrawEntitiesTrial.h"

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
