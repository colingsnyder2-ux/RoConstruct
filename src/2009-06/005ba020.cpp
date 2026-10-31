// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct X;
int g(X* p);
struct X {
    int f(int a);
};
int X::f(int a) { return g(this); }
