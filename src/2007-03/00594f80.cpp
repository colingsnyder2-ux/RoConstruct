// from server: 60% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 deque_double.cpp

// Candidate translation unit (score above; library headers required).
typedef double E;
#include <deque>
template class std::deque<E>;
