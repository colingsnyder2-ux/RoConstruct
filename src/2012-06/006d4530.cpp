// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B { void init(); char pad[0x808]; volatile int v; };
struct S { char pad[8]; B b; double f(); };
double S::f(){ B* p = &b; p->init(); return p->v * (1.0/2048); }
