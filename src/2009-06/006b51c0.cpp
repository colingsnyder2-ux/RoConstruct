// from server: 78% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
typedef int Tag;
struct R { void* p; R() : p(0) {} ~R(); };
struct Provider { void fetch(Tag t, int& type, std::string& s); };
extern Provider* provider;
R make(void* a, Tag t);
R load(void* a)
{
    std::string s;
    int type;
    Tag t;
    provider->fetch(t, type, s);
    switch (type) {
    case 0: return R();
    case 1: return make(a, t);
    default: return R();
    }
}
