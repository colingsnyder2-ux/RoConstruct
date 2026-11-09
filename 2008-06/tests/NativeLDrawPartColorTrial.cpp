#include "NativeLDrawEntitiesTrial.h"

namespace RBX { namespace LDraw2Lua {
bool LDrawPart::writeColor(std::ostream& out) const
{
    out << "part.BrickColor = BrickColor.new( " << output->mapColor(color) << " )";
    out << "\n";
    return true;
}
} }
