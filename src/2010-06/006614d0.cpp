// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 deque_wp.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/weak_ptr.hpp>
struct T; typedef boost::weak_ptr<T> E;
#include <deque>
template class std::deque<E>;
