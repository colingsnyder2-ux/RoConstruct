// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R { int m(int); };
struct I { virtual void a0(); virtual void a1(); virtual R* a2(); };
struct P { char pad[0x150]; I o; };
struct S { char pad[0xc]; P* p; int f(); };
int S::f() { R* r = p->o.a2(); return r->m(1); }