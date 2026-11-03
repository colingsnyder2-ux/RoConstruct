// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 list_double.cpp

// Candidate translation unit (score above; library headers required).
typedef double E;
#include <list>
template class std::list<E>;
