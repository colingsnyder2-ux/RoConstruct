// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_vectorctortailsaf2f5d73f288bd37.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
// Native vector occupies +4..+0x1b; target initializes two more words at1c and20.
struct S { virtual void method(); std::vector<unsigned int> items; unsigned int first,last; S(); };
S::S():items(),first(0),last(0) {}
