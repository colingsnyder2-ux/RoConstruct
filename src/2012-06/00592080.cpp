// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ void g(); };
struct S{ char p[0x1ef8]; B b; void h(); void f(); };
void S::f(){ b.g(); h(); }
