// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/rbxgs/Client/RbxGraphics/include /I{headers}/../../../tools/rbxgs/Client/Network/include /I{headers}/../../../tools/rbxgs/Client/RbxView/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/zlib /I{headers}/../../../tools/rbxgs/Client/Rendering/RenderLib/include /I{headers}/../../../tools/rbxgs/Client/Rendering/AppDraw/include /I{headers}/../../../tools/rbxgs/Client/boost_1_34_1/src /I{headers}/../../../tools/rbxgs/Client/App/lua-5.1.1/src /I{headers}/../../../tools/rbxgs/Client/Rendering/SDL-1.2.6/include /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
#include "G3D/CoordinateFrame.h"
#include "util/Utilities.h"
namespace RBX {
template<> std::string StringConverter<G3D::CoordinateFrame>::convertToString(const G3D::CoordinateFrame& value) {
 std::string result = StringConverter<G3D::Vector3>::convertToString(value.translation);
 for (int r = 0; r < 3; ++r) {
  for (int c = 0; c < 3; ++c) {
   result += ", ";
   result += StringConverter<float>::convertToString(value.rotation[r][c]);
  }
 }
 return result;
}
}
