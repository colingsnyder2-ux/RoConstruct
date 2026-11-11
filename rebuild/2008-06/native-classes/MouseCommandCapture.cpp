// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// MouseCommandCapture | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 6b43510d | roc native-status --write
#include "v8datamodel/MouseCommand.h"

namespace RBX {
void MouseCommand::capture()
{
    capturedMouse = true;
}
}
