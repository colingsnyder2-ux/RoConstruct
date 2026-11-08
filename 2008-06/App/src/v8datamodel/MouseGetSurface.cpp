// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// MouseGetSurface | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
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
