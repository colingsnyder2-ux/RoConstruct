// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Sub { void m(); };
struct S { char p[0x84]; Sub s; void a(int); void f(int v); };
void S::f(int v) { a(v); s.m(); }