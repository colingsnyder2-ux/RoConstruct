// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// LDrawMapRootLifetime | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 4677a4aa | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::map<int,RBX::LDraw2Lua::LDraw2RobloxColorMap *,std::less<int>,std::allocator<std::pair<int const ,RBX::LDraw2Lua::LDraw2RobloxColorMap *> > >;
