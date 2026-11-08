// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// SurfaceToolInteractions | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 78e9c85d | roc native-status --write
#include "tool/SurfaceTool.h"
#include "v8datamodel/Workspace.h"
#include "util/Sound.h"
#include "AppDraw/DrawAdorn.h"

namespace RBX {
void recordCameraHistory(const char*, const Instance*);
MouseCommand* SurfaceTool::onMouseDown(const UIEvent& input) {
    onMouseHover(input);
    if (surface) {
        applyToSurface(surface);
        ServiceProvider::create<Soundscape::SoundService>(reinterpret_cast<Instance*>(workspace))->playSound(PING_SOUND);
        recordCameraHistory(cursor.c_str(), reinterpret_cast<Instance*>(workspace));
        workspace->getDataState().setDirty(true);
    }
    return NULL;
}
void SurfaceTool::onMouseHover(const UIEvent& input) {
    PartInstance* part;
    surface = getSurface(input, part, surfaceId);
    partInstance = shared_from(surface ? part : NULL);
}
void SurfaceTool::render3dAdorn(Adorn* adorn) {
    if (partInstance)
        DrawAdorn::partSurface(partInstance->getPart(), surfaceId, adorn, G3D::Color4(G3D::Color3::orange(), 1.0f));
}
}
