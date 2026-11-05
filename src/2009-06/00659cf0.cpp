// from server: 100% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_67d3f66bcd1999bc.cpp

// Candidate translation unit (score above; library headers required).
#include "G3D/CoordinateFrame.h"
#include "G3D/g3dmath.h"
#include <math.h>
#pragma intrinsic(atan2)
extern const float inversePeriod;
extern const float period;
struct Camera {
 char prefix[0xdc]; G3D::CoordinateFrame cameraGoal;
 void panRadians(float);
 void panSteps(int);
};
void Camera::panSteps(int steps) {
 G3D::Vector3 look = cameraGoal.lookVector();
 float heading = atan2(-look.z, -look.x);
 int current = G3D::iRound(heading * inversePeriod + steps);
 panRadians(heading - current * period);
}

