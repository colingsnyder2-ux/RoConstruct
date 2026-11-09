// from server: 68% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /GS- /EHsc /MD
#include <excpt.h>
struct _EXCEPTION_POINTERS; typedef _EXCEPTION_POINTERS EXCEPTION_POINTERS;
extern "C" __declspec(dllimport) void __stdcall RaiseException(unsigned long, unsigned long, unsigned long, const unsigned long*);
struct Handler { int handle(EXCEPTION_POINTERS* p); };
extern Handler* g_handler;
int handleException(EXCEPTION_POINTERS* p)
{
    if (!p) {
        int r;
        __try {
            RaiseException(0x80000003, 0, 0, 0);
        }
        __except (r = handleException(GetExceptionInformation()), EXCEPTION_EXECUTE_HANDLER) {
        }
        return r;
    } else {
        return g_handler->handle(p);
    }
}
