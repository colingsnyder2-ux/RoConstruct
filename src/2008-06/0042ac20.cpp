// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_stringcallbacknoreturnff77f4fa6261fcbc.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
// The binary has no return path after this exception helper.
namespace boost { template<class E> __declspec(noreturn) void throw_exception(E const&); }
#include <boost/function.hpp>
template class boost::function1<void,std::string>;
