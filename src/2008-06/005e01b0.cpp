// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_manual_lexical_08dcad64789e8cca.cpp

// Candidate translation unit (score above; library headers required).
#include <exception>
#define BOOST_NO_EXCEPTIONS
namespace boost{__declspec(noreturn) void throw_exception(const std::exception&);}
#include <boost/lexical_cast.hpp>
#include <string>
unsigned short convertShort(const std::string&s){return boost::lexical_cast<unsigned short>(s);}
