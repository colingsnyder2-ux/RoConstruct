#include "StandardVerbs.h"
#include "util/Math.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"

namespace RBX {
G3D::Matrix3 TiltSelectionVerb::getRotationAxis() {
    return Math::matrixTiltQuadrant(Math::toYAxisQuadrant(workspace->getCamera()->getCameraCoordinateFrame()));
}
}
