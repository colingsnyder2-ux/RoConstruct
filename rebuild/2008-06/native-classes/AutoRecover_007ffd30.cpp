// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Sky.h"

// INFERRED: This definition generates the dynamic atexit destructor.
// Relocation targets remain unverified.
RBX::Reflection::BoundProp<RBX::TextureId, 1> RBX::Sky::prop_SkyRt(
    "SkyboxRt", "Appearance", &RBX::Sky::skyRt,
    RBX::Reflection::PropertyDescriptor::STANDARD);
