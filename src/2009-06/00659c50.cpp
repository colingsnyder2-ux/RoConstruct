// from server: 100% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_1f803bc329e89eed.cpp

// Candidate translation unit (score above; library headers required).
#include "G3D/CoordinateFrame.h"
#include "G3D/g3dmath.h"
extern const float radiansToDegrees;
namespace RBX { namespace Math { float getElevation(const G3D::Vector3&); } }
struct Camera {
 char prefix[0xdc]; G3D::CoordinateFrame cameraGoal;
 bool tiltRadians(float);
 void tiltSteps(int steps);
};
void Camera::tiltSteps(int steps) {
 float elevation = RBX::Math::getElevation(cameraGoal.lookVector());
 int current = G3D::iRound(elevation * radiansToDegrees * 0.1f);
 tiltRadians((current + steps) * 0.17453292f - elevation);
}

