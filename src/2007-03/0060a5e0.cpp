// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 map_ptr_pod12.cpp

// Candidate translation unit (score above; library headers required).
struct E { float v[3]; };
#include <map>
struct K; template class std::map<K*, E>;
