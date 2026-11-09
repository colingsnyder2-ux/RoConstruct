// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string
#include "util/LDrawEntities.h"
#include <cstdlib>

namespace RBX { namespace LDraw2Lua {
bool LDrawPart::writeTransform(std::ostream& out, std::string offset) const
{
    double value = atof(offset.c_str());
    double px = values[0] * 0.05;
    double py = values[1] * -0.05 - value;
    double pz = values[2] * -0.05;
    double r00 = values[3], r01 = values[4], r02 = values[5];
    double r10 = values[6], r11 = values[7], r12 = values[8];
    double r20 = values[9], r21 = values[10], r22 = values[11];
    out << "part.CFrame = CFrame.new("
        << px << "," << py << "," << pz << ","
        << r00 << "," << r01 << "," << r02 << "," << r10 << "," << r11 << ","
        << r12 << "," << r20 << "," << r21 << "," << r22 << ")";
    out << "\n";
    return false;
}
} }
