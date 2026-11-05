// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
void g(int* a, int* b);
struct S { int a; int b; void f(int x); };
void S::f(int) { g(&a, &b); }
