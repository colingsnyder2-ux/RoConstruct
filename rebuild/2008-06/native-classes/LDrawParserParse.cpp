// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /I{headers}/std-noinline-ldraw-parse
// >>> native-status (generated) -- do not edit >>>
// LDrawParserParse | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 3703c272 | roc native-status --write
#include "util/LDrawParser.h"
#include "util/LDrawMapRoot.h"
#include "util/LDrawEntities.h"
#include <fstream>
#include <memory>

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
