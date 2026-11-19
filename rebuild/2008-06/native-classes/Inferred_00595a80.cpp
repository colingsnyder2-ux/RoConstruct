// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00595a80: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "util/Name.h"

extern unsigned char flag;

void __cdecl f(void)
{
    if (flag)
    {
        __try
        {
        }
        __except (-1)
        {
        }
    }
}
