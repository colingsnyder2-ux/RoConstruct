// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "G3D/VAR.h"
#include <new>
#include <stdlib.h>

#pragma optimize("g", off)

extern "C" G3D::VAR g_00973908;
extern "C" void __cdecl fn_007fc6b0();

extern "C" void __cdecl fn_007f2780()
{
    new (&g_00973908) G3D::VAR();
    atexit(fn_007fc6b0);
}
