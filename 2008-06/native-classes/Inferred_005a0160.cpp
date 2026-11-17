// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: sub_005a0160 (placeholder name for 005a0160 from the identity tier): tests the four WASD flags (+4..+7) of MovementKeys; body byte-proved
#include "util/MovementKeys.h"
namespace RBX {
bool MovementKeys::sub_005a0160() const
{
    return w || s || a || d;
}
}
