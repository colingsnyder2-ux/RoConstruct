// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// LDrawEntityLifetime | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src dcba1e1f | roc native-status --write
#include "util/LDrawEntities.h"

namespace RBX { namespace LDraw2Lua {
LDrawItem::~LDrawItem() {}
LDrawModel::LDrawModel(const char* value) : name(value) {}
LDrawModel::~LDrawModel()
{
    unsigned int count = items.size();
    for (unsigned int i = 0; i < count; ++i) {
        LDrawItem* item = items.at(i);
        if (item) delete item;
    }
    items.erase(items.begin(), items.end());
}
void LDrawModel::add(LDrawItem* item) { LDrawItem* copy = item; items.push_back(copy); }

LDrawPart::LDrawPart(LDraw2RobloxMapRoot* owner) : output(owner)
{
    values[0] = 0.0; values[1] = 0.0; values[2] = 0.0; values[3] = 0.0;
    type = 0;
    values[4] = 0.0;
    color = 0;
    values[5] = 0.0; values[6] = 0.0; values[7] = 0.0; values[8] = 0.0;
    values[9] = 0.0; values[10] = 0.0; values[11] = 0.0;
    (void)std::string(""); // The original constructs and discards this temporary.
}
} }
