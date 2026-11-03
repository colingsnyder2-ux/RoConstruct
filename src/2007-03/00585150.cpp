// from server: 100% by colin
// roc-cl: 50727
// roc-lang: cpp
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll map_int_sp.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct T; typedef boost::shared_ptr<T> E;
#include <map>
template class std::map<int, E>;
