// =============================================================================
// LDrawParser.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/LDrawParser.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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

#include "util/LDrawEntities.h"
#include <fstream>

namespace RBX { namespace LDraw2Lua {
extern std::auto_ptr<LDraw2RobloxMapRoot> currentMap;
typedef char LDrawPartSize[sizeof(LDrawPart) == 0x90 ? 1 : -1];

void LDrawParser::parse(std::ostream& out)
{
    out << "-- " << "Roblox LDraw2Lua Conversion" << "\n";
    out << "-- " << "FileName: " << fileName.c_str() << "\n";
    out << "\n";
    LDrawModel model("LDrawModel");
    {
        std::ifstream file(fileName.c_str());
        char buffer[2048];
        if (!file.eof()) do {
            int type;
            file >> type;
            if (type == 1) {
                LDrawPart* part = new LDrawPart(currentMap.get());
                part->type = 1;
                int color = -1;
                file >> color;
                part->color = color;
                double value = 0.0;
                file >> value; part->values[0] = value;
                file >> value; part->values[1] = value;
                file >> value; part->values[2] = value;
                file >> value; part->values[3] = value;
                file >> value; part->values[4] = value;
                file >> value; part->values[5] = value;
                file >> value; part->values[6] = value;
                file >> value; part->values[7] = value;
                file >> value; part->values[8] = value;
                file >> value; part->values[9] = value;
                file >> value; part->values[10] = value;
                file >> value; part->values[11] = value;
                file.getline(buffer, 2000);
                std::string line(buffer);
                part->setName(line.substr(line.find_first_not_of(" ", 0), line.size()));
                model.add(part);
            } else {
                file.getline(buffer, 2000);
            }
        } while (!file.eof());
    }
    model.writeLua(out);
}
} }
