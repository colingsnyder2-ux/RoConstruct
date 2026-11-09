// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MD
#include <stdlib.h>
int __cdecl run(void* p);
unsigned long __stdcall threadProc(void* p)
{
    int r = run(p);
    _exit(1);
}
