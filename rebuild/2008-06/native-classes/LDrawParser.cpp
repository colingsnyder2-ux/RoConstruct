// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
