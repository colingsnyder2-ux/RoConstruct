// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "G3D/Vector3.h"

// INFERRED: cdecl helper taking Vector3*; threshold double at 0x82cef8 is unknown, 1e-5 guessed.
extern "C" bool fn_0053f9e0(const G3D::Vector3* v)
{
    if (!v->isFinite())
        return false;
    for (int i = 0; i < 3; ++i) {
        if (!(G3D::abs((double)(*v)[i]) > 1e-5))
            return false;
    }
    return true;
}
