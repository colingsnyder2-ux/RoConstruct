// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
struct K; struct V;
struct Holder {
    std::map<const K*, const V*> m;
    int a, b, c, d;
    Holder() : a(0), b(0), c(0), d(0) {}
};
Holder& get() { static Holder h; return h; }
