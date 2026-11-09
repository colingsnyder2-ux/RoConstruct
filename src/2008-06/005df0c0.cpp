// from server: 100% by colin
// from server: 95% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_mutsearch_005df0c0_6499ab485ee84ab4.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off,push)
#include "G3D/CoordinateFrame.h"
void pan(G3D::CoordinateFrame& frame,float amount){G3D::Vector3 look=frame.lookVector();G3D::Vector3 side(look.z,look.y,-look.x);frame.lookAt(frame.translation+(look+amount * side));}
