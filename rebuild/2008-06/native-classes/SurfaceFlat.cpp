// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// >>> native-status (generated) -- do not edit >>>
// SurfaceFlat | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src e99dde96 | roc native-status --write
#undef _RELEASEASSERT
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Surface.h"

namespace RBX {
void Surface::flat()
{
    if (partInstance->primitive.getSurfaceType(surfId) != NO_SURFACE) {
        partInstance->primitive.setSurfaceType(surfId, NO_SURFACE);
        partInstance->onSurfaceChanged(surfId);
        partInstance->raisePropertyChanged(partInstance->getSurfaces().getSurfaceType(surfId));
    }
    setSurfaceInput(SurfaceData::empty().inputType);
    setParamA(SurfaceData::empty().paramA);
    setParamB(SurfaceData::empty().paramB);
}
}
