// from server: 100% by EspClaude
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet roc_espclaude_871364548f72285c.cpp

// Candidate translation unit (score above; library headers required).
#include "BitStream.h"
#undef BITSTREAM_STACK_ALLOCATION_SIZE
#define BITSTREAM_STACK_ALLOCATION_SIZE 1024
#include "BitStream.cpp"
