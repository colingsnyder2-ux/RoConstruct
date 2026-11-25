// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "G3D/g3dmath.h"

// INFERRED: G3D Vector4::operator/=(float) - multiplies by 1/k, or sets all components to (float)G3D::inf() when k == 0.
extern "C" float* __fastcall fn_007baf50(float* self, int unusedEdx, float k)
{
    if (k != 0.0f) {
        float r = 1.0f / k;
        self[0] *= r;
        self[1] *= r;
        self[2] *= r;
        self[3] *= r;
    } else {
        self[0] = (float)G3D::inf();
        self[1] = (float)G3D::inf();
        self[2] = (float)G3D::inf();
        self[3] = (float)G3D::inf();
    }
    return self;
}
