// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "../native-headers/util/UserInputBase.h"

namespace RBX {
UserInputBase::UserInputBase()
    : currentCursorId(),
      currentCursor(NULL)
{
}
}
