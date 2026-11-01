// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct It { int a, b; };
struct R { int a, b, c; };
struct C {
    It h();
    R g(int x, It it);
    R f(int x);
};
R C::f(int x) { return g(x, h()); }
