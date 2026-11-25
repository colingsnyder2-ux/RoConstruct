// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "LocalBackpack2008/LocalBackpack2008.h"

namespace RBX
{
    LocalBackpack::LocalBackpack()
        : lastRemovedIndex(-1)
    {
        yLocation = Rect::BOTTOM;
    }
}
