// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
#include <algorithm>
struct C { int x; };
struct sptr { C* px; void* pn; C* get() const { return px; } };
struct Binder {
    void (C::*f)(int);
    int a;
    Binder(void (C::*ff)(int), int aa) : f(ff), a(aa) {}
    void operator()(const sptr& p) { (p.get()->*f)(a); }
};
template Binder std::for_each(std::vector<sptr>::iterator, std::vector<sptr>::iterator, Binder);
