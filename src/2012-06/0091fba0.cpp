// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct C{ void h(); }; struct A{ char p[0xd0]; C* c; void f(); };
void A::f(){ if (c) c->h(); }
