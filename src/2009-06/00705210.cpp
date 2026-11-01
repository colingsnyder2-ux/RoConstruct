// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /EHsc /MD
#include <string.h>
struct Crash { virtual void boom(); };
extern bool g_crashEnabled;
void crashWithMessage(const char* msg)
{
    if (g_crashEnabled) {
        char buf[128];
        strncpy_s(buf, 128, msg, 128);
        Crash* p = 0;
        p->boom();
    }
}
