#include "StandardVerbs.h"
#include "util/Math.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/ICameraOwner.h"
namespace RBX {
G3D::Matrix3 TiltSelectionVerb::getRotationAxis() {
    ICameraOwner* camera = reinterpret_cast<ICameraOwner*>(reinterpret_cast<char*>(workspace.get()) + 0x288);
    return Math::matrixTiltQuadrant(Math::toYAxisQuadrant(camera->getGCamera().getCoordinateFrame()));
}
}

