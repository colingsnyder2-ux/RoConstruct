// native-flags: /Og /Oy- /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <utility>

typedef std::pair<int, std::string> Local_00550f60_Pair;

extern "C" Local_00550f60_Pair* __fastcall fn_00550f60(Local_00550f60_Pair* self, int unusedEdx, const Local_00550f60_Pair* other)
{
    Local_00550f60_Pair* volatile p = self;
    const Local_00550f60_Pair* volatile& q = *(const Local_00550f60_Pair* volatile*)&other;
    p->first = q->first;
    const std::string& s = q->second;
    p->second.std::basic_string<char>::basic_string(s);
    return p;
}
