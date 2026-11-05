// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_distancevaluenative_a1a61a363bfdc68c.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector3.h>
using namespace G3D;
extern float defaultValue,distanceScale,distanceThreshold;
float __cdecl distanceValue(const Vector3* a,const Vector3* b){float distance=(*a-*b).magnitude();float result=defaultValue;if(distance>distanceThreshold)result=distance*distanceScale;return result;}
