// from server: 60% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 set_sp.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct T; typedef boost::shared_ptr<T> E;
#include <set>
template class std::set<E>;
