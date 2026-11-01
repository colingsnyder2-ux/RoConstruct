// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct NameBase { std::string a; int b; NameBase(const NameBase& o) : a(o.a), b(o.b) {} };
struct NamedItem : NameBase {
    std::string c;
    NamedItem(const NamedItem& o);
};
NamedItem::NamedItem(const NamedItem& o) : NameBase(o), c(o.c) {}
