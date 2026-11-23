// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/UserInputBase.h"

namespace RBX {
void UserInputBase::init(Adorn* adorn)
{
	setCursorId(adorn, ContentId::fromAssets("Textures\\ArrowCursor.png"));
}
}
