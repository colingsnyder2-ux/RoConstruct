#include "NativeLDrawParserTrial.h"
#include <map>

namespace RBX { namespace LDraw2Lua {
class LDraw2RobloxColorMap;
class LDraw2RobloxPartMap;
class LDraw2RobloxMapRoot {
public:
    virtual ~LDraw2RobloxMapRoot();
    std::string path, version;
    std::map<int, LDraw2RobloxColorMap*> colors;
    std::map<std::string, LDraw2RobloxPartMap*> parts;
    explicit LDraw2RobloxMapRoot(std::string);
};
extern LDraw2RobloxMapRoot* currentMap;
std::string resolveMapPath(const char*);
typedef char MapRootSize[sizeof(LDraw2RobloxMapRoot) == 0x7c ? 1 : -1];
typedef char ParserSize[sizeof(LDrawParser) == 0x20 ? 1 : -1];

LDrawParser::LDrawParser(const char* path) : fileName(path)
{
    if (!currentMap) {
        LDraw2RobloxMapRoot* replacement = new LDraw2RobloxMapRoot(resolveMapPath("fonts\\LDraw2RobloxMap.xml"));
        if (replacement != currentMap && currentMap) delete currentMap;
        currentMap = replacement;
    }
}
} }
