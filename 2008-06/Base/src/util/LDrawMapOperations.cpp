// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// LDrawMapOperations | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src 9a7ac793 | roc native-status --write
#include "util/LDrawMapRoot.h"
#include <algorithm>
#include <cctype>

int stringCompareNoCase(const std::string&, const std::string&);

namespace RBX { namespace LDraw2Lua {
LDraw2RobloxColorMap::~LDraw2RobloxColorMap() {}
LDraw2RobloxPartMap::~LDraw2RobloxPartMap() {}

LDraw2RobloxColorMap::LDraw2RobloxColorMap(int ldraw, int roblox)
    : ldrawCode(ldraw), robloxCode(roblox) {}

NativeRobloxPart::NativeRobloxPart(int shape, int formFactor, std::string size, std::string offset)
    : shape(shape), formFactor(formFactor), size(size), offset(offset) {}

LDraw2RobloxPartMap::LDraw2RobloxPartMap(std::string name, std::string description, std::string filename, int fidelity)
    : name(name), description(description), filename(filename), fidelity(fidelity) {}

void LDraw2RobloxPartMap::addPart(const NativeRobloxPart& part)
{
    parts.push_back(part);
}

LDraw2RobloxColorMap* LDraw2RobloxMapRoot::findColor(int color)
{
    std::map<int, LDraw2RobloxColorMap*>::iterator it = colors.find(color);
    return it != colors.end() ? it->second : NULL;
}

int LDraw2RobloxMapRoot::mapColor(int color)
{
    LDraw2RobloxColorMap* mapping = findColor(color);
    return mapping ? mapping->robloxCode : 1;
}

std::string LDraw2RobloxPartMap::getFilename() const
{
    return filename;
}

LDraw2RobloxPartMap* LDraw2RobloxMapRoot::findPart(const std::string& name)
{
    std::map<std::string, LDraw2RobloxPartMap*>::iterator it = parts.find(name);
    return it != parts.end() ? it->second : NULL;
}

LDraw2RobloxPartMap* LDraw2RobloxMapRoot::findPartCaseInsensitive(const std::string& name)
{
    std::string lower(name);
    std::transform(lower.begin(), lower.end(), lower.begin(), tolower);
    return findPart(lower);
}

NativeRobloxPart* LDraw2RobloxPartMap::getPart()
{
    return parts.size() > 0 ? &parts.at(0) : NULL;
}

void LDraw2RobloxMapRoot::addPartMap(LDraw2RobloxPartMap* part)
{
    std::string filename = part->getFilename();
    std::transform(filename.begin(), filename.end(), filename.begin(), tolower);
    LDraw2RobloxPartMap* previous = findPart(filename);
    if (previous) delete previous;
    parts[filename] = part;
}
int LDraw2RobloxMapRoot::readFidelity(std::string value)
{
    { bool match; { std::string text("exact"); match = stringCompareNoCase(value, text) == 0; } if (match) return 0; }
    { bool match; { std::string text("close"); match = stringCompareNoCase(value, text) == 0; } if (match) return 1; }
    return 2;
}

int LDraw2RobloxMapRoot::readShape(std::string value)
{
    { bool match; { std::string text("ball"); match = stringCompareNoCase(value, text) == 0; } if (match) return 0; }
    { bool match; { std::string text("block"); match = stringCompareNoCase(value, text) == 0; } if (match) return 1; }
    { bool match; { std::string text("cylinder"); match = stringCompareNoCase(value, text) == 0; } if (match) return 2; }
    return 999;
}

int LDraw2RobloxMapRoot::readFormFactor(std::string value)
{
    { bool match; { std::string text("symmetric"); match = stringCompareNoCase(value, text) == 0; } if (match) return 0; }
    { bool match; { std::string text("brick"); match = stringCompareNoCase(value, text) == 0; } if (match) return 1; }
    return 2;
}
} }
