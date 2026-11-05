// from server: 100% by colin
// from server: 88% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_005cbf90_0c4f1ca71fa6c099.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off,push)
#include <G3D/Vector3.h>
struct Camera{char prefix[0x198];G3D::Vector3 position;char gap[0x24];G3D::Vector3 focus;int canZoom(int);};


int Camera::canZoom(int direction){G3D::Vector3 v=position-focus;float distance=sqrtf(v.x*v.x+v.y*v.y+v.z*v.z);if(direction>0){if(!(distance>.5f))return 0;}else if(!(distance<1000.0f))return 0;return 1;}
