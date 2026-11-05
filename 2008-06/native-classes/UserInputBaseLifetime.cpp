// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/UserInputBase.h"

typedef char NativeUserInputBaseSize[sizeof(RBX::UserInputBase) == 0x28 ? 1 : -1];

namespace RBX {
UserInputBase::UserInputBase() : currentCursor(NULL) {}
UserInputBase::~UserInputBase() {}
}
