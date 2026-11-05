// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct T { void h(); };
struct S { T& g(int x); void f(int x); };
void S::f(int x) { g(x).h(); }
