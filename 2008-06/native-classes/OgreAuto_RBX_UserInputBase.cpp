// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../native-headers/util/UserInputBase.h"

namespace RBX {
UserInputBase::UserInputBase()
    : currentCursorId(),
      currentCursor(NULL)
{
}
}

namespace RBX {
UserInputBase::~UserInputBase()
{
}
}

