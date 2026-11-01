// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
class Matcher {
public:
    int pad0;
    int type;
    const std::string* name;
    bool matches(const std::string* s) const;
};
bool Matcher::matches(const std::string* s) const
{
    switch (type) {
    case 1: return s == name;
    case 2: { const std::string& n = *name; return s->compare(n) == 0; }
    default: return false;
    }
}
