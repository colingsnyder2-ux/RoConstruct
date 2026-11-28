// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <intrin.h>

namespace RBX { namespace Render {

__int64 __cdecl GetCyclesDifference(void (__cdecl *func)(unsigned int), unsigned int arg)
{
    unsigned int startLo, startHi, endLo, endHi;
    __try
    {
        // INFERRED: timestamps kept in try-local 64-bit temporaries and split
        // into 32-bit halves only after the second rdtsc.
        unsigned __int64 s = __rdtsc();
        func(arg);
        unsigned __int64 e = __rdtsc();
        endHi = (unsigned int)(e >> 32);
        endLo = (unsigned int)e;
        startHi = (unsigned int)(s >> 32);
        startLo = (unsigned int)s;
    }
    __except (1)
    {
        // INFERRED: fault in func yields 0.
        return 0;
    }
    // INFERRED: the end-high term is a real multiply (__allmul); the start-high term is a shift.
    return (__int64)endHi * 4294967296LL
         - ((__int64)startHi << 32)
         - (__int64)startLo
         + (__int64)endLo;
}

} }
