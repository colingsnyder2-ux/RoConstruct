#include "tool/SurfaceTool.h"
#include "AppDraw/DrawAdorn.h"

namespace RBX {

void DrawAdorn::partSurface(const Part& part, int surfaceId, Adorn* adorn, const G3D::Color4& color)
{
    adorn->setObjectToWorldMatrix(part.coordinateFrame);
    G3D::Vector3 halfRealSize = part.gridSize * 0.5f;

    surfaceBorder(adorn, halfRealSize, 0.2f, surfaceId, color);
}

}
