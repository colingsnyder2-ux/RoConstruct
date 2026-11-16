#pragma float_control(precise, off)
#include "v8datamodel/Camera.h"
#include "util/Math.h"
#include "v8datamodel/Workspace.h"
#include <algorithm>
#include "v8datamodel/ICameraOwner.h"
#include "G3D/g3dmath.h"
#include <math.h>
#pragma intrinsic(atan2)

namespace RBX {
extern const float cameraRadiansToDegrees;
void Camera::panUnits(int steps) {
    G3D::Vector3 look = cameraGoal.lookVector();
    float heading = atan2(-look.z, -look.x);
    int current = G3D::iRound(heading * 1.2732394933700562f + steps);
    panRadians(heading - current * 0.7853981852531433f);
}

bool Camera::tiltUnits(int steps) {
    float elevation = Math::getElevation(cameraGoal.lookVector());
    int current = G3D::iRound(elevation * cameraRadiansToDegrees * 0.1f);
    return tiltRadians((current + steps) * 0.1745329350233078f - elevation);
}
}

namespace RBX {
// Original 005cc010: focus translation assignment followed by CoordinateFrame::lookAt.
void Camera::lookAt(const G3D::Vector3& point) {
    cameraFocus.translation = point;
    cameraGoal.lookAt(point);
}
bool Camera::canZoom(int direction) const {
    float distance = goalToFocusDistance();
    if (direction > 0) { if (distance <= distanceMin()) return false; }
    else { if (distance >= distanceMax()) return false; }
    return true;
}
}

namespace RBX {
bool Camera::canTilt(int direction) const {
    float elevation = Math::getElevation(cameraGoal.lookVector());
    if (direction < 0) return elevation >= -1.5707963705062866f;
    return elevation <= 1.5707963705062866f;
}
}

namespace RBX {
void Camera::onWrapMouse(const G3D::Vector2& delta) {
    tiltRadians(delta.y * -0.0052359881810843945f);
    panRadians(delta.x * -0.0069813174195587635f);
}
}

namespace RBX {
void Camera::autoMode() {
    if (animationType != AUTO) {
        animationType = AUTO;
        if (ICameraOwner* owner = getCameraOwner()) owner->cameraMoved();
    }
}
}

namespace RBX {
bool Camera::askSetParent(const Instance* instance) const {
    return dynamic_cast<const Workspace*>(instance) != NULL;
}
float Camera::getNewZoomDistance(float currentDistance, float in) {
    if (in > 0.0f) currentDistance = (std::max)(currentDistance / (1.0f + in * 0.25f), 0.5f);
    else if (in < 0.0f) currentDistance = (std::min)(currentDistance * (1.0f - in * 0.25f), 1000.0f);
    return currentDistance;
}
}
