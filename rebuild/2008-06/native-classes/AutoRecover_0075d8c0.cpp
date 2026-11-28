// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "MyXTPCommandBars.h"

// INFERRED: The thunk receives its object in ECX; a cdecl parameter cannot
// reproduce that register-only interface without inline assembly.
extern "C" unsigned long __cdecl fn_0075d8c0(char* self)
{
    return reinterpret_cast<CCmdTarget*>(self - 0x54)->InternalRelease();
}
