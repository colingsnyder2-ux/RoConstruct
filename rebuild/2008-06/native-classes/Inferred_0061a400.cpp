// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_0061a400 (placeholder name for 0061a400 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"

namespace RBX {

struct InletArg;

bool __fastcall sub_0061a400(void** self, int /*edx*/, int first, int* argument)
{
    if (argument[2] != ((int*)self)[6])
        return false;
    typedef bool (__thiscall *DispatchFn)(void*, int, int);
    return ((DispatchFn)(*(void***)self)[15])(self, first, argument[3]);
}

}
