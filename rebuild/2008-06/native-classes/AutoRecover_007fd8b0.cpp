// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Sky.h"

RBX::Reflection::BoundProp<RBX::TextureId, 1> RBX::Sky::prop_SkyRt(
    "SkyboxRt", "Appearance", &RBX::Sky::skyRt,
    RBX::Reflection::PropertyDescriptor::STANDARD);
