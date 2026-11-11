// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// MouseGetSurface | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by Espeon (deepseek:deepseek-chat)
// <<< native-status | src f943870e | roc native-status --write
#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/PartInstance.h"

namespace RBX {
Surface* MouseCommand::getSurface(const UIEvent& input, PartInstance*& part, int& id)
{
    part = getPart(input, NULL);
    if (part) {
        G3D::Ray ray = getUnitMouseRay(input);
        if (Surface* surface = part->getSurface(ray, id)) return surface;
    }
    return NULL;
}
}
