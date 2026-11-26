// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct P { char p[0x1c]; };
struct B { int x; };
struct D : P, B {};
struct O { void m(B*); };
struct S { int a, b; D* d; O* o; void f(); };
void S::f() { o->m(d); }