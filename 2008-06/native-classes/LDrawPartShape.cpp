// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-ldraw-shape
// >>> native-status (generated) -- do not edit >>>
// LDrawPartShape | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src ddbdce15 | roc native-status --write
#include "util/LDrawEntities.h"

namespace RBX { namespace LDraw2Lua {
bool LDrawPart::writeShape(std::ostream& out, const NativeRobloxPart* part) const
{
    out << "-- " << "Part Description -------------------------------------" << "\n";
    out << "part = Instance.new(\"Part\")" << "\n";
    std::string label = name.substr(0, name.find_first_of(".", 0));
    out << "part.Name = \"" << label.c_str() << "\"" << "\n";
    int shape = part->shape;
    out << "part.Shape = " << shape << "\n";
    if (shape != 0 && shape != 2) {
        int formFactor = part->formFactor;
        out << "part.FormFactor = " << formFactor << "\n";
    } else
        out << "part.FormFactor = 0  -- symmetric" << "\n";
    out << "part.Size = Vector3.new(" << part->size.c_str() << ")" << "\n";
    return true;
}
} }
