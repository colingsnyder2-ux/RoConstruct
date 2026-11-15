// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/MouseCommand.h"

namespace RBX {
void MouseCommand::capture()
{
    capturedMouse = true;
}
}
