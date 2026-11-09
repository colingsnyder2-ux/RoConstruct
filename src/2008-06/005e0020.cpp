// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_lexicalint64_4634dd74d4413aa3.cpp

// Candidate translation unit (score above; library headers required).
#include <exception>
#define BOOST_NO_EXCEPTIONS
namespace boost{ __declspec(noreturn) void throw_exception(const std::exception&); }
#include <boost/lexical_cast.hpp>
#include <string>
__int64 __cdecl convert(const std::string& text){return boost::lexical_cast<__int64>(text);}
