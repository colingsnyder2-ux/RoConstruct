// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>
#include <math.h>

// The original object was built with /fp:fast; reproduce that at function scope.
#pragma float_control(precise, off, push)

// INFERRED: local stand-in for G3D::Vector3 (12 bytes, returned via hidden pointer).
struct FnVec3 {
    float x, y, z;
};

// G3D uniformRandom(-1, 1)
static inline float fnUniformRandom(float low, float high)
{
    return (rand() * (high - low) / (float)RAND_MAX) + low;
}

// G3D Vector3::random(): rejection-sample inside the unit sphere, then unitize.
// INFERRED: exported symbol name per the convention; hidden-pointer return written as an explicit pointer.
extern "C" FnVec3* fn_00518650(FnVec3* result)
{
    result->x = 0.0f;
    result->y = 0.0f;
    result->z = 0.0f;
    do {
        // Arguments are evaluated right to left: the first rand() call feeds z.
        float z = fnUniformRandom(-1.0f, 1.0f);
        float y = fnUniformRandom(-1.0f, 1.0f);
        float x = fnUniformRandom(-1.0f, 1.0f);
        result->x = x;
        result->y = y;
        result->z = z;
    } while (result->x * result->x + result->y * result->y + result->z * result->z >= 1.0f);

    float fMagnitude = (float)sqrt((double)(result->x * result->x + result->y * result->y + result->z * result->z));
    if (fMagnitude > 1e-06f) {
        float fInv = 1.0f / fMagnitude;
        result->x *= fInv;
        result->y *= fInv;
        result->z *= fInv;
    }
    return result;
}

#pragma float_control(pop)
