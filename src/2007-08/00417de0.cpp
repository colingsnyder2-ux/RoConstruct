// from server: 92% by EspClaude
// from server: 55% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS /EHsc /MD
// roc-lib: openrbx-client roc_claude_eabfd831e03488dd.cpp

// Candidate translation unit (score above; library headers required).
// Codegen analog: boost 1.34.1 shared_count(Y*) instantiated for the map that
// boost date_time's greg_month.cpp keeps in a shared_ptr (its checked_delete is
// the 2007-08 function 00417d90 that this ctor's catch handler calls).
// The library preprocessing pass runs without /EHsc, so _CPPUNWIND is missing
// and boost/config would select BOOST_NO_EXCEPTIONS; the exe was built with
// exceptions on (target has the try/catch frame), so restore that setting.
#include <boost/config.hpp>
#undef BOOST_NO_EXCEPTIONS
#include <map>
#include <string>
#include <boost/shared_ptr.hpp>

typedef std::map<std::string, unsigned short> roc_month_map;
template boost::detail::shared_count::shared_count(roc_month_map *);
