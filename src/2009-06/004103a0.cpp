// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 roc_espclaude_baf452402f1f67d3.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG
#include <boost/shared_ptr.hpp>
#include <boost/exception/exception.hpp>
template class boost::exception_detail::clone_impl<boost::exception_detail::error_info_injector<boost::bad_weak_ptr> >;
