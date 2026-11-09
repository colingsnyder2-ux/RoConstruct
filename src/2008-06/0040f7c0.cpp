// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc 2008-06 0040f7c0: std::find over std::list<std::string> (checked iterators, imported string operator==)
#include <string>
#include <list>
#include <algorithm>

typedef std::list<std::string> List;

List::iterator __cdecl find(List::iterator first, List::iterator last, const std::string& value)
{
    return std::find(first, last, value);
}
