// from server: 100% by colin
// from server: 89% by coldek
// from server: 82% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// Exact construct: ATL CComCriticalSection::Init pattern (__try body, __except on 0xC0000017 -> raiseError(0x8007000e)).
// The __try/__finally {} variant compiled a bogus call 0x58 funclets and no filter body (77%).
#include <excpt.h>
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void*);
__declspec(noreturn) void raiseError(long);
struct S {S();};
S::S()
{
    __try
    {
        InitializeCriticalSection(this);
    }
    __except (GetExceptionCode() == 0xC0000017)
    {
        raiseError(0x8007000e);
    }
}
