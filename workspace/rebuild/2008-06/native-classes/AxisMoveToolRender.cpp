// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// AxisMoveToolRender | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 57e00f3e | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/MegaDragger.h"
#include "tool/AxisMoveTool.h"
#include "tool/AxisMoveGrid.h"
#include "v8datamodel/ICameraOwner.h"
#include "util/Extents.h"
#include "AppDraw/DrawAdorn.h"
namespace RBX {
void AxisMoveTool::render2d(Adorn* adorn) {
    Extents box;
    if (bounds(box)) {
        G3D::CoordinateFrame frame(box.center());
        G3D::Vector3 size = box.size();
        DrawAdorn::handles2d(size, frame,
            workspace->getGCamera(), adorn, G3D::Color3::orange());
    }
}
void AxisMoveTool::render3dAdorn(Adorn* adorn) {
    Extents box;
    if (bounds(box)) {
        G3D::CoordinateFrame frame(box.center());
        G3D::Vector3 size = box.size();
        DrawAdorn::handles3d(size, frame, adorn, HANDLE_MOVE,
            workspace->getGCamera().getCoordinateFrame().translation);
    }
}
}
