// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "G3D/Matrix3.h"
#include "G3D/g3dmath.h"

// INFERRED: the argument is a Matrix3 passed by pointer or reference (same ABI),
// and the function checks that every element is finite.
extern "C" bool fn_0053f970(const G3D::Matrix3* m)
{
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            if (!G3D::isFinite((double)(*m)[r][c])) {
                return false;
            }
        }
    }
    return true;
}
