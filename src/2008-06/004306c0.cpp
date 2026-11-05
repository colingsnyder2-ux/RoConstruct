// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_globalpair_31391fc200652c51.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Pair;
extern Pair global_pair;
Pair __cdecl func_004306c0() { return global_pair; }
