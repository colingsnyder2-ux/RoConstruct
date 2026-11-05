// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_directionscaledvector_863727e03b82d3af.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Matrix3.h>
#include <math.h>
using namespace G3D;
extern const float factor,angleOffset,angleScale;
extern const double sectorScale;
#pragma intrinsic(atan2)
#pragma float_control(precise, off)
inline double angle(const Vector3& v,float scale){Vector3 scaled=v*scale;return atan2(-scaled.x,-scaled.z);}
int direction(const Matrix3* matrix){float scale=factor;return (int)floor((angle(matrix->getColumn(2),scale)+angleOffset)*angleScale*sectorScale)%4;}
