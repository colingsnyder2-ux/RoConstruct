// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <limits>

// INFERRED: this is the static initializer for a G3D Vector3 constant
// (Vector3::inf) built from three inlined calls to G3D::inf().
// inf() holds a function-local static, which explains the repeated guard
// checks on the one guard bit at 0x96f020.
// INFERRED: the three destination floats are the x/y/z members of a global
// Vector3 at 0x973834.
extern float g_00973834;
extern float g_00973838;
extern float g_0097383c;

static inline double g3d_inf()
{
    static double i = std::numeric_limits<double>::infinity();
    return i;
}

extern "C" void fn_007f25e0()
{
    float x = (float)g3d_inf();
    float y = (float)g3d_inf();
    float z = (float)g3d_inf();
    g_00973834 = x;
    g_00973838 = y;
    g_0097383c = z;
}
