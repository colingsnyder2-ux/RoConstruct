// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 vector_pod16.cpp

// Candidate translation unit (score above; library headers required).
struct E { float v[4]; };
#include <vector>
template class std::vector<E>;
