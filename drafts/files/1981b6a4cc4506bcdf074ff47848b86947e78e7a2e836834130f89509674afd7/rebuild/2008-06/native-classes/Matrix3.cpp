// >>> native-status (generated) -- do not edit >>>
// Matrix3 | 2008-06 | selection unverified
// 0/2 mapped addresses reported exact (subset) | no mapped strings | historical| by auto
// <<< native-status | src 77509ce2 | roc native-status --write
#include "G3D/Matrix3.h"

namespace G3D {

void Matrix3::setColumn(int iCol, const Vector3 &vector) {
    debugAssert((iCol >= 0) && (iCol < 3));
    elt[0][iCol] = vector.x;
    elt[1][iCol] = vector.y;
    elt[2][iCol] = vector.z;
}

Matrix3 Matrix3::transpose () const {
    Matrix3 kTranspose;

    for (int iRow = 0; iRow < 3; iRow++) {
        for (int iCol = 0; iCol < 3; iCol++) {
            kTranspose[iRow][iCol] = elt[iCol][iRow];
        }
    }

    return kTranspose;
}

}
