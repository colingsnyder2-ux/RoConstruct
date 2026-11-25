// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8tree/Service.h"

// INFERRED: function-local static initialized from ServiceProvider::newIndex()
// (the SEH frame and the guard bit in the disassembly come from the static init)
extern "C" unsigned int fn_0045b2b0()
{
    static unsigned int value = RBX::ServiceProvider::newIndex();
    return value;
}
