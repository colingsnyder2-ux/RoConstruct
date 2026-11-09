// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_eef87882ccabb668.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <G3D/CoordinateFrame.h>
#include "util/Math.h"
extern const float negativeOne;
struct Camera {char prefix[0x174];G3D::CoordinateFrame rotation;int canTilt(int);};
int Camera::canTilt(int direction){G3D::Vector3 look=rotation.lookVector();float angle=RBX::Math::elevationAngle(look);if(direction<0){if(!(angle >= -1.5707963705062866f))return false;}else{if(!(angle<=1.5707963705062866f))return false;}return true;}

