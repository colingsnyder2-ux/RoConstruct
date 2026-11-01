// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <algorithm>
struct A;
struct B { int v; };
struct C { void handle(B b, A* a); };
struct F {
    void (C::*f)(B, A*);
    C* obj;
    B b;
    void operator()(A* a) const { (obj->*f)(b, a); }
};
template F std::for_each<std::vector<A*>::iterator, F>(std::vector<A*>::iterator, std::vector<A*>::iterator, F);
