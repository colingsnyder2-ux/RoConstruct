// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct Pair { std::string s; int n; };
struct G { char pad[8]; int off; Pair get(void* i) const; };
Pair G::get(void* i) const
{
    char* o = i ? (char*)i - 0x1c : 0;
    return *(Pair*)(o + off);
}
