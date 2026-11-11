// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// UserInputBaseLifetime | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src c8ab8988 | roc native-status --write
#include "util/UserInputBase.h"

typedef char NativeUserInputBaseSize[sizeof(RBX::UserInputBase) == 0x28 ? 1 : -1];

namespace RBX {
UserInputBase::UserInputBase() : currentCursor(NULL) {}
UserInputBase::~UserInputBase() {}
}
