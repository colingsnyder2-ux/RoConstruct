// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_unit_a7fedc0da5d9156a.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <set>
struct T;
template class std::map<T*, std::set<T*> >;
