// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <locale>

// INFERRED: use_facet<ctype<char>> instance, cdecl, locale ref in, facet out.
extern "C" const std::ctype<char>& fn_0064f910(const std::locale& loc);

extern "C" char* fn_0064fa80(const char* first, const char* last, char* dest, const std::locale& loc)
{
    if (first != last) {
        do {
            char c = *first;
            *dest = fn_0064f910(loc).tolower(c);
            ++first;
            ++dest;
        } while (first != last);
        return dest;
    }
    return dest;
}
