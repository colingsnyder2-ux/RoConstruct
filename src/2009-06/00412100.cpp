// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 roc_espclaude_d3a72d03c3966d61.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/date_time/gregorian/greg_month.hpp>
#include <boost/exception/exception.hpp>
template boost::exception_detail::enable_error_info_return_type<boost::gregorian::bad_month>::type boost::enable_error_info<boost::gregorian::bad_month>(boost::gregorian::bad_month const&);
