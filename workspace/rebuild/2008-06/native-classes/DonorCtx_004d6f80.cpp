// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/rbxgs/Client/RbxGraphics/include /I{headers}/../../../tools/rbxgs/Client/Network/include /I{headers}/../../../tools/rbxgs/Client/RbxView/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/zlib /I{headers}/../../../tools/rbxgs/Client/Rendering/RenderLib/include /I{headers}/../../../tools/rbxgs/Client/Rendering/AppDraw/include /I{headers}/../../../tools/rbxgs/Client/boost_1_34_1/src /I{headers}/../../../tools/rbxgs/Client/App/lua-5.1.1/src /I{headers}/../../../tools/rbxgs/Client/Rendering/SDL-1.2.6/include /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 004d6f80: translated from its byte-exact mined analog against the 2007 rbxgs donor headers (donor_translate.py); byte-proved standalone
#include <G3D/Vector3.h>

struct CSHA1 {
    char padding[0x270];
    float x, y, z;
    G3D::Vector3 getVector() const;
};

G3D::Vector3 CSHA1::getVector() const
{
    G3D::Vector3 result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}

