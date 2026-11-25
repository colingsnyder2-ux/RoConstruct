// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Sky.h"

// The native map places Sky's atexit thunk at 0x007ffa70.
// The supplied 0x008007d0 disassembly uses Rocket::prop_targetRadius storage.
// This definition emits the requested Sky symbol.

RBX::Reflection::BoundProp<RBX::TextureId, 1> RBX::Sky::prop_SkyRt(
    "SkyboxRt", "Appearance", &RBX::Sky::skyRt,
    RBX::Reflection::PropertyDescriptor::STANDARD);
