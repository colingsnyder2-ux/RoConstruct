#include "NativeAxisMoveToolTrial.h"
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
        dragPoint = Math::toGrid(point, Dragger::dragSnap());
        dragRay = G3D::Ray::fromOriginAndDirection(dragPoint, normalIdToVector3(face));
        capture();
        return this;
    }
    return ArrowToolBase::onMouseDown(event);
}
}
