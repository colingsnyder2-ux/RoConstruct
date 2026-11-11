// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// AxisMoveToolDown | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src e3f8e7a7 | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/MegaDragger.h"
#include "tool/AxisMoveTool.h"
#include "tool/AxisMoveGrid.h"
#include "tool/Dragger.h"
#include "util/Math.h"
#include "util/Extents.h"
namespace RBX {
bool hitMoveHandles(const Extents&, const G3D::Ray&, G3D::Vector3&, NormalId&);
bool AxisMoveTool::hitHandle(const UIEvent& event, G3D::Vector3& point, NormalId& face) {
    Extents box;
    if (bounds(box)) {
        if (hitMoveHandles(box, getUnitMouseRay(event), point, face)) return true;
    }
    return false;
}
MouseCommand* AxisMoveTool::onMouseDown(const UIEvent& event) {
    G3D::Vector3 point;
    NormalId face;
    if (hitHandle(event, point, face)) {
        mouseDownView = event.mousePosition;
        axis = face % 3;
        dragPoint = Math::toGrid(point, axisMoveGrid());
        dragRay = G3D::Ray::fromOriginAndDirection(dragPoint, normalIdToVector3(face));
        capture();
        return this;
    }
    return ArrowToolBase::onMouseDown(event);
}
}
