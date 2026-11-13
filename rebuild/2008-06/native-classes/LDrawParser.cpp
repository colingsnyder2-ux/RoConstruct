// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// >>> native-status (generated) -- do not edit >>>
// LDrawParser | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by auto (+1) (chatgpt:gpt-6.1-sol)
// <<< native-status | src 9f5c8495 | roc native-status --write
#include "util/LDrawParser.h"
#include "util/LDrawMapRoot.h"
#include <memory>

namespace RBX { namespace LDraw2Lua {
extern std::auto_ptr<LDraw2RobloxMapRoot> currentMap;
std::string resolveMapPath(const char*);
typedef char MapRootSize[sizeof(LDraw2RobloxMapRoot) == 0x7c ? 1 : -1];
typedef char ParserSize[sizeof(LDrawParser) == 0x20 ? 1 : -1];

LDrawParser::LDrawParser(const char* path) : fileName(path)
{
    if (!currentMap.get())
        currentMap.reset(new LDraw2RobloxMapRoot(resolveMapPath("fonts\\LDraw2RobloxMap.xml")));
}

LDrawParser::~LDrawParser() {}

} }
