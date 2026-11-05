// from server: 100% by EspClaude
// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: g3d-6.09-png-dll roc_espclaude_fe634362cd870ed1.cpp

// Candidate translation unit (score above; library headers required).
extern "C" {
#define PNG_INTERNAL
#define big_row_buf big_row_buf; char exePad2009[0x20]
#include "png.h"
#undef big_row_buf
#include "pngmem.c"
}
