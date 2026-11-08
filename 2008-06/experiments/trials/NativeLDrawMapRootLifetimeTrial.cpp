#include "NativeLDrawMapRootTrial.h"

namespace RBX { namespace LDraw2Lua {
LDraw2RobloxMapRoot::~LDraw2RobloxMapRoot()
{
    std::map<int, LDraw2RobloxColorMap*>::iterator color;
    for (color = colors.begin(); color != colors.end(); ++color) delete color->second;
    std::map<std::string, LDraw2RobloxPartMap*>::iterator part;
    for (part = parts.begin(); part != parts.end(); ++part) delete part->second;
}
} }
