// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <sstream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/throw_exception.hpp>

// INFERRED: this is boost::lexical_cast<int>(const std::string&) inlined as a standalone function.
extern "C" int fn_005be120(const std::string& arg)
{
    std::stringstream ss;
    ss.unsetf(std::ios_base::skipws);
    ss.precision(10);

    int result;
    if (!(ss << arg).fail() && !(ss >> result).fail() && ss.get() == EOF)
        return result;

    boost::throw_exception(boost::bad_lexical_cast());
    return 0;
}
