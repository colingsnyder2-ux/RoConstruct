// from server: 92% by EspClaude
// from server: 56% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: boost-1.40.0 roc_claude_522a7034efc41571.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1   // /EHsc defines this; the recipe preprocessor runs without it
// shared_count(Y*) constructor: pi_ = new sp_counted_impl_p<Y>(p) (operator new(0x10), use=weak=1).
#include <boost/shared_ptr.hpp>

namespace roc_analog { struct Udata_t { ~Udata_t(); }; }

template boost::detail::shared_count::shared_count(roc_analog::Udata_t*);
