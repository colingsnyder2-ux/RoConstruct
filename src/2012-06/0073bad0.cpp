// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <map>
#include <string>
struct V { char b[0x8]; };
typedef std::map<std::string, V> Map;
void dist(Map::iterator first, Map::iterator last, int& n)
{
    for (; first != last; ++first) ++n;
}
