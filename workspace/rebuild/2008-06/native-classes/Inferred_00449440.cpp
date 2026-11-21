// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_00449440 (placeholder name for 00449440 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"

int nativeStartupMode;

int __fastcall sub_00449440(const char* source)
{
    if (!nativeStartupMode)
        nativeStartupMode = *reinterpret_cast<const int*>(source + 0x130);
    return nativeStartupMode;
}
