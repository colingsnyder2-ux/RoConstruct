#include "NativeSurfaceToolTrial.h"
#include "v8datamodel/PartInstance.h"
#include "AppDraw/DrawAdorn.h"
namespace RBX {
void SurfaceTool::render3dAdorn(Adorn* adorn) {
    if (partInstance)
        DrawAdorn::partSurface(partInstance->getPart(), surfaceId, adorn, G3D::Color4(G3D::Color3::orange(), 1.0f));
}
}
