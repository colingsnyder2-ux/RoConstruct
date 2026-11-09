#include "v8datamodel/PartInstance.h"
#include "util/Math.h"
namespace RBX {
void __cdecl movePart(PartInstance* part, const G3D::Vector3& offset) {
    G3D::CoordinateFrame frame = part->getCoordinateFrame();
    frame.translation += offset;
    if (part->aligned()) frame = Math::snapToGrid(frame, 0.1f);
    part->setCoordinateFrame(frame);
}
}
