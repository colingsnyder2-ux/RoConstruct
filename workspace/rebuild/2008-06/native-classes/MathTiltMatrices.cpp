// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// MathTiltMatrices | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 2a87f6b3 | roc native-status --write
#include "util/Math.h"

namespace RBX {
const G3D::Matrix3 Math::matrixTiltQuadrant(int quadrant)
{
    switch (quadrant) {
    case 0: return G3D::Matrix3(1, 0, 0, 0, 0, -1, 0, 1, 0);
    case 1: return matrixTiltZ();
    case 2: return G3D::Matrix3(1, 0, 0, 0, 0, 1, 0, -1, 0);
    case 3: return matrixTiltNegativeZ();
    default: return G3D::Matrix3::identity();
    }
}
}
