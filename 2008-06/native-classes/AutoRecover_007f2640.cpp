// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <limits>

// INFERRED: g3d's G3D::nan() returns a reference to a function-local static.
// Because every call yields the same address, the compiler can run all three
// guard checks first and then load the value once.
static inline const double& g3dNan()
{
    static double n = std::numeric_limits<double>::quiet_NaN();
    return n;
}

// INFERRED: Vector3 layout (three floats) with a float constructor.
struct NanVec3 {
    float x, y, z;
    NanVec3() {}
    NanVec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

static NanVec3 g_nanVec;

// Compiler-generated dynamic initializer for the g3d static
// Vector3 nan constant: Vector3(nan(), nan(), nan()).
extern "C" void fn_007f2640()
{
    const double& a = g3dNan();
    const double& b = g3dNan();
    const double& c = g3dNan();
    g_nanVec.x = (float)a;
    g_nanVec.y = (float)b;
    g_nanVec.z = (float)c;
}
