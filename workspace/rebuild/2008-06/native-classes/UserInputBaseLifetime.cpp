// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// UserInputBaseLifetime | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by king_originala (mixed 2)
// <<< native-status | src c8ab8988 | roc native-status --write
#include "util/UserInputBase.h"

typedef char NativeUserInputBaseSize[sizeof(RBX::UserInputBase) == 0x28 ? 1 : -1];

namespace RBX {
UserInputBase::UserInputBase() : currentCursor(NULL) {}
UserInputBase::~UserInputBase() {}
}
