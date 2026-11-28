// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/Name.h"

namespace RBX {

// INFERRED: the mangled type PADA with a $1 template argument matches an unsized char array (MSVC encodes arrays as PAD), so the template argument is the array decaying to a pointer.
extern char sControllerService[];

// INFERRED: callDoDeclare tail-jumps to the shared declare routine at 0x45b160, so an explicit instantiation reproduces it.
template void Name::callDoDeclare<sControllerService>();

}
