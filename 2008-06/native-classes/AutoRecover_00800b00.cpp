// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Sky.h"

namespace RBX
{
    // MSVC generates the __cdecl atexit destructor from this definition.
    // INFERRED: Byte match at 0x00800b00 is unverified.
    Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt(
        "SkyboxRt", "Appearance", &Sky::skyRt,
        Reflection::PropertyDescriptor::STANDARD);
}
