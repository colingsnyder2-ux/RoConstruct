// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// LDrawMapRootLifetime | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src b05fde40 | roc native-status --write
#include "util/LDrawMapRoot.h"

namespace RBX { namespace LDraw2Lua {
LDraw2RobloxMapRoot::~LDraw2RobloxMapRoot()
{
    std::map<int, LDraw2RobloxColorMap*>::iterator color;
    for (color = colors.begin(); color != colors.end(); ++color) delete color->second;
    std::map<std::string, LDraw2RobloxPartMap*>::iterator part;
    for (part = parts.begin(); part != parts.end(); ++part) delete part->second;
}
} }
