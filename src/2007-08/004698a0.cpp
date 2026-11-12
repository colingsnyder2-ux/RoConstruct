// from server: 81% by EspClaude
// roc 2007-08 004698a0  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 244 bytes
// Copy the name, lower-case it with std::transform(..., tolower) (0x469520,
// tolower through the MSVCR80 IAT), then look it up (thiscall 0x469840).
#include <string>
#include <algorithm>
#include <ctype.h>

namespace RBX { namespace LDraw2Lua {

class LDraw2RobloxColorMap
{
public:
    int lookup(const std::string& name);       // 0x469840
    int convert(const std::string& name);
};

int LDraw2RobloxColorMap::convert(const std::string& name)
{
    std::string lower(name);
    std::transform(lower.begin(), lower.end(), lower.begin(), tolower);
    return lookup(lower);
}

}}
