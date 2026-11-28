// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include <math.h>

// INFERRED: G3D Vector3::isZero() -> fuzzyEq(squaredMagnitude(), 0.0f)
namespace G3D {
    double eps(double a, double b);
}

extern "C" bool __fastcall fn_006662f0(const float* self, int unusedEdx)
{
    float sq = self[0] * self[0] + self[1] * self[1] + self[2] * self[2];
    double d = sq;
    return (d == 0.0) || (fabs(d - 0.0) <= G3D::eps(d, 0.0));
}
