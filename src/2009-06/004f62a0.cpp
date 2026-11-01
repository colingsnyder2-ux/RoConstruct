// from server: 100% by EspClaude
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet roc_espclaude_07f5a341d19fa18b.cpp

// Candidate translation unit (score above; library headers required).
#include <malloc.h>
#include <stdlib.h>
#define alloca _malloca
extern void (*rakFree)(void*);
#define free rakFree
#include "ReliabilityLayer.cpp"
