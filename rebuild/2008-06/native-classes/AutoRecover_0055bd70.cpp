// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// The original is a one-instruction import thunk that jumps to MSVCP90's
// std::operator==<char, char_traits<char>, allocator<char>>(const string&, const string&).
// INFERRED: both arguments are const std::string& (from the mangled name), cdecl, returns bool.
extern "C" bool fn_0055bd70(const std::string& lhs, const std::string& rhs)
{
    return std::operator==(lhs, rhs);
}
