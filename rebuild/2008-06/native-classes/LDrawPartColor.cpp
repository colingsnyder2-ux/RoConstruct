// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/LDrawEntities.h"

namespace RBX { namespace LDraw2Lua {
bool LDrawPart::writeColor(std::ostream& out) const
{
    out << "part.BrickColor = BrickColor.new( " << output->mapColor(color) << " )";
    out << "\n";
    return true;
}
} }
