// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R { int m(); };
struct I { virtual void a0(); virtual void a1(); virtual R* a2(); };
struct S { char pad[0xac]; I* p; int f(); };
int S::f() { R* r = p->a2(); return r->m(); }