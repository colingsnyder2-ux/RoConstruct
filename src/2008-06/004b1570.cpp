// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_simplevectorctor_927296398355f2b0.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
struct Base {char data[0x24];Base();~Base();};
struct S:Base {std::vector<void*> storage;S();};
S::S(){}
