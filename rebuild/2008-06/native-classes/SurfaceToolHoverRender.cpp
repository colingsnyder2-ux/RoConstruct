// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// SurfaceToolHoverRender | 2008-06 | draft (no current byte proof)
// 0/3 mapped addresses byte-exact | 3 unproved | no mapped strings | by king_originala (+1) (mixed 2)
// <<< native-status | src e7ac4daa | roc native-status --write
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

// 00677630 (identity registry ?partSurface@DrawAdorn@RBX@@SAXABVPart@2@HPAVAdorn@2@ABVColor4@G3D@@@Z; it directly
// follows the AppDraw range 006770b0..00677629 of DrawPartAdorn.cpp, which does not define it, and no other native
// file does). Adorn::setObjectToWorldMatrix (vtable +0x38) on part.coordinateFrame (+0x38), gridSize (+0x04) times
// __real@3f000000 0.5f, then DrawAdorn::surfaceBorder 006774a0 with __real@3e4ccccd 0.2f. Codegen analog of the donor
// AppDraw/DrawAdorn.cpp body. Owner note: it belongs with DrawPartAdorn.cpp's AppDraw unit if that file is extended.
// /fp:fast (file flags) follows the AppDraw unit DrawPartAdorn.cpp; rejected variant: without it 0.5f loads as
// `fld qword` (double constant) at insn 12 instead of the original `fld dword ptr [0x819bac]`.
void DrawAdorn::partSurface(const Part& part, int surfaceId, Adorn* adorn, const G3D::Color4& color)
{
    adorn->setObjectToWorldMatrix(part.coordinateFrame);
    G3D::Vector3 halfRealSize = part.gridSize * 0.5f;

    surfaceBorder(adorn, halfRealSize, 0.2f, surfaceId, color);
}
}
