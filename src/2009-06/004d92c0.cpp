// from server: 98% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <set>
struct T; typedef T* E;
struct Count { void* pi; Count() : pi(0) {} ~Count(); };
struct SP {
    void* px; Count pn;
    SP() : px(0) {}
};
struct S {
    SP p;
    std::set<E> s;
    int n;
    S();
};
S::S() : n(0) {}
