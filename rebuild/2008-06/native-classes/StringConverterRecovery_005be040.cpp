// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/rbxgs/Client/RbxGraphics/include /I{headers}/../../../tools/rbxgs/Client/Network/include /I{headers}/../../../tools/rbxgs/Client/RbxView/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/zlib /I{headers}/../../../tools/rbxgs/Client/Rendering/RenderLib/include /I{headers}/../../../tools/rbxgs/Client/Rendering/AppDraw/include /I{headers}/../../../tools/rbxgs/Client/boost_1_34_1/src /I{headers}/../../../tools/rbxgs/Client/App/lua-5.1.1/src /I{headers}/../../../tools/rbxgs/Client/Rendering/SDL-1.2.6/include /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include /fp:fast
#include <limits>
#include <stdio.h>
#include "util/Utilities.h"
namespace RBX {
template<> std::string StringConverter<float>::convertToString(const float& value) {
 volatile int state = 0;
 char buffer[32];
 if (std::numeric_limits<float>::infinity() == value) return "INF";
 if (-std::numeric_limits<float>::infinity() == value) return "-INF";
 if (!(value < 0.0f || value >= 0.0f)) return "NAN";
 _snprintf(buffer, 32, "%.9g", value);
 return buffer;
}
}
