// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Sky.h"

// INFERRED: accessor names getSkyboxRt/setSkyboxRt (property name is "SkyboxRt"); the previous getSkyRt/setSkyRt did not exist in Sky.h.
// INFERRED: constructor arguments; the atexit destructor does not depend on them.
namespace RBX {
Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt("SkyboxRt", "Appearance", &Sky::getSkyboxRt, &Sky::setSkyboxRt);
}
