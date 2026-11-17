// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/rbxgs/Client/RbxGraphics/include /I{headers}/../../../tools/rbxgs/Client/Network/include /I{headers}/../../../tools/rbxgs/Client/RbxView/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/zlib /I{headers}/../../../tools/rbxgs/Client/Rendering/RenderLib/include /I{headers}/../../../tools/rbxgs/Client/Rendering/AppDraw/include /I{headers}/../../../tools/rbxgs/Client/boost_1_34_1/src /I{headers}/../../../tools/rbxgs/Client/App/lua-5.1.1/src /I{headers}/../../../tools/rbxgs/Client/Rendering/SDL-1.2.6/include /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 00659330: translated from its byte-exact mined analog against the 2007 rbxgs donor headers (donor_translate.py); byte-proved standalone
#include "util/Vector3int32.h"

bool __cdecl intersects(const RBX::Vector3int32* a, const RBX::Vector3int32* b)
{
    if (a[0].x <= b[1].x &&
        a[0].y <= b[1].y &&
        a[0].z <= b[1].z &&
        a[1].y >= b[0].y &&
        a[1].x >= b[0].x &&
        a[1].z >= b[0].z)
        return true;
    return false;
}

