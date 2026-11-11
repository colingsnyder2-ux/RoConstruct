// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// MouseGetDecal | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 2120e6b8 | roc native-status --write
#undef _RELEASEASSERT
#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Surface.h"
#include "v8datamodel/Decal.h"

namespace RBX {
inline NormalId FaceInstance::getFace() const { return face; }

Decal* MouseCommand::getDecal(PartInstance* part, const UIEvent& input)
{
    int normal;
    Surface* surface = getSurface(input, part, normal);
    if (surface && part->children) {
        std::vector<boost::shared_ptr<Instance> >::const_iterator end = part->children->end();
        std::vector<boost::shared_ptr<Instance> >::const_iterator it = part->children->begin();
        for (; it != end; ++it) {
            Decal* decal = dynamic_cast<Decal*>(it->get());
            if (decal && decal->getFace() == surface->getNormalId()) return decal;
        }
    }
    return NULL;
}
}
