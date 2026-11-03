// from server: 24% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 map_int_wp.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/weak_ptr.hpp>
struct T; typedef boost::weak_ptr<T> E;
#include <map>
template class std::map<int, E>;
