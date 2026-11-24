// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <sstream>
#include <typeinfo>

// INFERRED: boost::lexical_cast<__int64>(const std::string&) instance, written without boost headers.
struct bad_lexical_cast_local : std::bad_cast {
    bad_lexical_cast_local() : std::bad_cast("bad cast") {}
};

extern "C" void fn_00501890(const bad_lexical_cast_local& e);

extern "C" __int64 fn_005e0020(const std::string& s)
{
    std::stringstream ss;
    ss.unsetf(std::ios_base::skipws);
    ss.precision(19);

    __int64 value;
    if (!(ss << s).fail() && !(ss >> value).fail() && ss.get() == EOF)
        return value;

    fn_00501890(bad_lexical_cast_local());
    return 0;
}
