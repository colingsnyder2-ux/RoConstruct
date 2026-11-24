// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <algorithm>

// INFERRED: original is std::transform(begin, end, begin, op) with a cdecl wrapper.
extern "C" void fn_0064fd00(std::string* s, int (*op)(int))
{
    std::transform(s->begin(), s->end(), s->begin(), op);
}
