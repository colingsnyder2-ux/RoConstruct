#include "NativeLDrawEntitiesTrial.h"

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
