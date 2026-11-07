// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// MouseCommandLifetime | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 9e31d4a6 | roc native-status --write
#include "v8datamodel/MouseCommand.h"
namespace RBX {
MouseCommand::MouseCommand(Workspace* value) : capturedMouse(false), workspace(value) {}
MouseCommand::~MouseCommand() {}
}
