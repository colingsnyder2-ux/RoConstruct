// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/UserInputBase.h"

namespace RBX {

void UserInputBase::init(Adorn* adorn)
{
	// INFERRED: the ContentId temp is copied into a TextureId temp, which is then
	// passed by const reference to the virtual setCursorId (vtable slot 7).
	setCursorId(adorn, ContentId::fromAssets("Textures\\ArrowCursor.png"));
}

}
