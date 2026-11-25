// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <math.h>

// INFERRED: G3D Vector3::isZero() -> fuzzyEq(squaredMagnitude(), 0.0)
namespace G3D {
    double eps(double a, double b);
}

// INFERRED: local stand-in for G3D::Vector3 (x,y,z floats at 0,4,8)
struct FnVec3 {
    float x, y, z;
};

extern "C" int __fastcall fn_006662f0(FnVec3* self, int unusedEdx)
{
    // INFERRED: kept in double precision (vendor built with /fp:fast, no float spill)
    double sq = (double)self->x * self->x + (double)self->y * self->y + (double)self->z * self->z;
    if (sq == 0.0)
        return 1;
    return fabs(sq) <= G3D::eps(sq, 0.0);
}
