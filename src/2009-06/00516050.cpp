// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <set>
struct E { int v[6]; bool operator<(const E& o) const { return v[0] < o.v[0]; } };
struct S {
    std::set<E> a;
    std::set<E> b;
    int c, d, e, f;
    S();
};
S::S() : c(0), d(0), e(0), f(0) {}
