// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Sky.h"

// INFERRED: This definition generates the dynamic atexit destructor.
// The supplied comparison shows identical instructions with relocations masked;
// it does not identify which relocation differs.
RBX::Reflection::BoundProp<RBX::TextureId, 1> RBX::Sky::prop_SkyBk(
    "SkyboxBk", "Appearance", &RBX::Sky::skyBk,
    RBX::Reflection::PropertyDescriptor::STANDARD);
