// from server: 100% by EspClaude
// roc 2007-08 004ef1a0  TU-local static: vector is finite and every |component| <= 1e10 (custom esi convention from the caller)
#include <math.h>
namespace G3D {
bool isFinite(double x);
}

struct Vector3 {
    float x, y, z;
    float operator[](int i) const { return (&x)[i]; }
};

static __declspec(noinline) bool isLegal(const Vector3& v)
{
    if (!G3D::isFinite(v.x) || !G3D::isFinite(v.y) || !G3D::isFinite(v.z))
        return false;
    for (int i = 0; i < 3; ++i) {
        if (fabs((double)v[i]) > 1e10)
            return false;
    }
    return true;
}

bool checkPosition(const Vector3* p)
{
    return isLegal(*p);
}
