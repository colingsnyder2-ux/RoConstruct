// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/MouseCommand.h"

RBX::MouseCommand::MouseCommand(Workspace* workspace)
    : capturedMouse(false), workspace(workspace)
{
}
