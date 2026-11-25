// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

namespace G3D {
// INFERRED: minimal declaration; only the out-of-line default ctor is referenced
// (??0CoordinateFrame@G3D@@QAE@XZ at 0x4782d0).
class CoordinateFrame {
public:
    CoordinateFrame();
private:
    float storage[12];
};
}

// INFERRED: global G3D::CoordinateFrame object at 0x97386c
extern G3D::CoordinateFrame g_009738ac;
// INFERRED: exit-time destructor thunk for the global above (0x7fc640)
extern "C" void __cdecl fn_007fc6d0(void);

#pragma optimize("g", off)
extern "C" void fn_007f27c0(void)
{
    g_009738ac.G3D::CoordinateFrame::CoordinateFrame();
    atexit(fn_007fc6d0);
}
