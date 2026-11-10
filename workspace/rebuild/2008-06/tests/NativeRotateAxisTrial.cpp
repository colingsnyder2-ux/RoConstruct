#include "StandardVerbs.h"
#include "util/Math.h"

namespace RBX {
G3D::Matrix3 RotateSelectionVerb::getRotationAxis() {
    return Math::matrixRotateY();
}
}
