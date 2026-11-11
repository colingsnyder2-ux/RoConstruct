// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "v8datamodel/Camera.h"
#include "util/Math.h"
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
