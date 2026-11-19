// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../native-headers/util/LDrawEntities.h"

namespace RBX {
namespace LDraw2Lua {
LDrawModel::~LDrawModel()
{
    unsigned int count = items.size();
    for (unsigned int i = 0; i < count; ++i) {
        LDrawItem *p = items.at(i);
        if (p)
            delete p;
    }
    items.erase(items.begin(), items.end());
}
}
}
