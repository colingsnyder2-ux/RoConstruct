// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Sky.h"

namespace RBX
{
    // INFERRED: MSVC emits the named atexit thunk from this static member definition.
    Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt(
        "SkyboxRt", "Appearance", &Sky::skyRt,
        Reflection::PropertyDescriptor::STANDARD);
}
