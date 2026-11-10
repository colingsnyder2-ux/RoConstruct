// Inactive recovery candidate; not selected by a client build.
// Original targets: 005cbf90 (canZoom), 005cc040 (canTilt).
#include "v8datamodel/Camera.h"
#include "util/Math.h"
#include <math.h>

namespace RBX {
bool Camera::canZoom(int direction) const {
    G3D::Vector3 delta = cameraGoal.translation - cameraFocus.translation;
    float distance = sqrtf(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
    if (direction > 0) {
        if (!(distance > distanceMin())) return false;
    } else if (!(distance < distanceMax())) return false;
    return true;
}

bool Camera::canTilt(int direction) const {
    float elevation = Math::getElevation(cameraGoal.lookVector());
    if (direction < 0) {
        if (!(elevation >= -1.5707963705062866f)) return false;
    } else if (!(elevation <= 1.5707963705062866f)) return false;
    return true;
}
}
