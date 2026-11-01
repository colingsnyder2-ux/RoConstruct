// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <stdio.h>
struct S { char pad[0x54]; FILE* file; };
void flushIt(S* s) { if (s) { FILE* f = s->file; if (f) fflush(f); } }
