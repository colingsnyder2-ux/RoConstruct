// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
#include "tool/SurfaceTool.h"
#include "AppDraw/DrawAdorn.h"

namespace RBX {
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
