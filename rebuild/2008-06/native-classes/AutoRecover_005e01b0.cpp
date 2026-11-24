// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <sstream>
#include <boost/lexical_cast.hpp>

// INFERRED: this is boost::lexical_cast<unsigned short>(const std::string&) instantiated out of line.
// The disassembly shows the usual steps: stringstream, unsetf(skipws), precision(5),
// operator<<(string), operator>>(unsigned short), get()==EOF check, and a bad_lexical_cast throw otherwise.
extern "C" unsigned short fn_005e01b0(const std::string& s)
{
    return boost::lexical_cast<unsigned short>(s);
}
