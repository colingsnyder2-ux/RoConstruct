// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
bool f(const std::string& s, int* out)
{
    if (s.find("Jump") != 0) { *out = 0x20; return true; }
    if (s.find("Dismount") != 0) { *out = 8; return true; }
    return false;
}
