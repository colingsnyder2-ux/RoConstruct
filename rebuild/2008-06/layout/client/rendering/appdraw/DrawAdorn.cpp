// =============================================================================
// DrawAdorn.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/appdraw/DrawAdorn.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "tool/SurfaceTool.h"
#include "AppDraw/DrawAdorn.h"

namespace RBX
{

void DrawAdorn::partSurface(const Part& part, int surfaceId, Adorn* adorn, const G3D::Color4& color)
{
    adorn->setObjectToWorldMatrix(part.coordinateFrame);
    G3D::Vector3 halfRealSize = part.gridSize * 0.5f;

    surfaceBorder(adorn, halfRealSize, 0.2f, surfaceId, color);
}

}
