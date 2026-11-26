// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct C{ void h(); }; struct B{ char p[0x1c]; C* c; }; struct A{ char p[0x3c]; B* b; void f(); };
void A::f(){ b->c->h(); }
