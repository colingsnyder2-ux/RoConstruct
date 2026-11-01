// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Inner { std::string s; int c; };
struct Arg { int a; Inner i; };
struct Registry { bool add(Arg a, void* slot); };
extern Registry g;
struct X {
    Registry* r;
    int pad;
    int m;
    void init(Arg a);
};
void X::init(Arg a) { r = g.add(a, &m) ? &g : 0; }
