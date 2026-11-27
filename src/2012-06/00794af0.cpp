// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
bool f(const std::string& s, int* out)
{
    if (s.find("Poison") != 0) { *out = 0; return true; }
    if (s.find("Confusion") != 0) { *out = 1; return true; }
    return false;
}
