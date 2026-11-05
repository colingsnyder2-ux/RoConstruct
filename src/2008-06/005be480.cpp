// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_lexicalnumericfamilya52e07e2b09c48ec.cpp

// Candidate translation unit (score above; library headers required).
#include <exception>
#define BOOST_NO_EXCEPTIONS
namespace boost{__declspec(noreturn) void throw_exception(const std::exception&);}
#include <boost/lexical_cast.hpp>
#include <string>
int convertInt(const std::string&s){return boost::lexical_cast<int>(s);}
unsigned convertUnsigned(const std::string&s){return boost::lexical_cast<unsigned>(s);}
float convertFloat(const std::string&s){return boost::lexical_cast<float>(s);}
double convertDouble(const std::string&s){return boost::lexical_cast<double>(s);}
