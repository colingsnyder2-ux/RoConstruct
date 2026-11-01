// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <algorithm>
class Item;
struct SP { Item* px; void* pn; };
inline Item* get_pointer(const SP& p) { return p.px; }
class Item { public: bool matches(int a); };
struct MF {
    typedef bool (Item::*F)(int);
    F f_;
    bool call(const SP& u, void const*, int& b1) const { return (get_pointer(u)->*f_)(b1); }
    bool operator()(const SP& u, int a1) const { return call(u, &u, a1); }
};
struct List1 { const SP& a1; const SP& operator[](int) const { return a1; } };
struct List2 {
    int a2_;
    bool operator()(MF& f, List1& a) { return f(a[0], a2_); }
};
struct Pred {
    MF f_;
    List2 l_;
    bool operator()(const SP& a1) { List1 a = { a1 }; return l_(f_, a); }
};
template std::vector<SP>::iterator std::find_if(std::vector<SP>::iterator, std::vector<SP>::iterator, Pred);
