// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Sky.h"

// INFERRED: the function is the compiler-generated atexit destructor for this
// static, so I define the static. The destructor body deletes a heap pointer
// at offset 0x18 and resets the vtable to the base descriptor's. I did not
// compile this or check the header names.
namespace RBX {
const char* const sSkyRt = "SkyboxRt";
Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt("SkyboxRt", "Appearance", &Sky::getSkyRt, &Sky::setSkyRt);
}
