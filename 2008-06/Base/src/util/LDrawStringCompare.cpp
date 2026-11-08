// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string-iterators
// >>> native-status (generated) -- do not edit >>>
// LDrawStringCompare | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src 66082edc | roc native-status --write
#include <string>
#include <cctype>

int stringCompareNoCase(const std::string& left, const std::string& right)
{
    std::string::const_iterator a = left.begin();
    std::string::const_iterator b = right.begin();
    while (a != left.end() && b != right.end()) {
        if (::toupper(*a) != ::toupper(*b))
            return ::toupper(*a) < ::toupper(*b) ? -1 : 1;
        ++a;
        ++b;
    }
    unsigned int leftSize = left.size(), rightSize = right.size();
    if (leftSize == rightSize) return 0;
    return leftSize < rightSize ? -1 : 1;
}
