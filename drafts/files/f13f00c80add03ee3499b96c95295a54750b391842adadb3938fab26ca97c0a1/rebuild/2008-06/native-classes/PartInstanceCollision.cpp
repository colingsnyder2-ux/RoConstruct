// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
#undef _RELEASEASSERT
#include "v8datamodel/PartInstance.h"
namespace RBX {
// 00598d20 tests embedded Primitive dragging and collision flags.
bool PartInstance::getCanCollide() const {
    return !primitive.getDragging() && primitive.getCanCollide() ? true : false;
}
}
